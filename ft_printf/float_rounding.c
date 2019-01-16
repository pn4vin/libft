/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_rounding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:33:15 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/16 23:33:21 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strnum.h"
#include "ft_str.h"

char		*prepend_zeros2(char *s, int n)
{
	char	*r;
	size_t	i;
	size_t	len;
	int		offset;

	if (n <= 0)
		return (s);
	len = ft_slen(s);
	r = malloc(sizeof(char) * (n + len + 1));
	i = 0;
	if (s[i] == '-')
		r[i++] = '-';
	offset = 0;
	while (offset < n)
	{
		r[i + offset++] = '0';
	}
	while (i < len)
	{
		r[offset + i] = s[i];
		i++;
	}
	free(s);
	r[offset + i] = '\0';
	return (r);
}

t_bigint	*rounding_mask(int size)
{
	t_bigint	*bi;
	t_bigint	*tmp;
	t_bigint	*tmp2;
	int			i;

	bi = bi_zero();
	i = 0;
	tmp = bi_itobi(4);
	while (i < size)
	{
		bi_iadd(bi, tmp);
		bi_ishift10(bi, 1);
		i++;
	}
	bi_iadd(tmp, (tmp2 = bi_one()));
	bi_iadd(bi, tmp);
	bi_release(&tmp);
	bi_release(&tmp2);
	return (bi);
}

/*
** I know, it get crazy, believe me
*/

char		*actual_rounding(char *s, int offset, int *digit_exponent)
{
	char		*res;
	t_bigint	*tmp;
	t_bigint	*tmp2;
	t_bigint	*tmp3;

	tmp = bi_stobi(s);
	tmp2 = bi_ishift10(bi_itobi(1), (int)ft_slen(&s[offset]) - 1);
	tmp3 = bi_add(tmp, tmp2);
	res = bi_tostr(tmp3);
	if (ft_slen(res) < ft_slen(s))
		res = prepend_zeros2(res, ft_abs((int)ft_slen(res) - (int)ft_slen(s)));
	else if (ft_slen(res) > ft_slen(s))
		*digit_exponent += 1;
	free(s);
	bi_release(&tmp);
	bi_release(&tmp2);
	bi_release(&tmp3);
	return (res);
}

char		*d_round(char *s, int *digit_exponent, size_t prec)
{
	int			offset;
	t_bigint	*sb;
	t_bigint	*p;

	offset = (int)(*digit_exponent >= 0 ? *digit_exponent + prec : prec);
	if (s[0] == '-')
		offset += 1;
	if (prec >= ft_slen(&s[*digit_exponent + 1]))
		return (s);
	sb = bi_stobi(&s[offset + 1]);
	p = rounding_mask((int)ft_slen(&s[offset + 2]));
	if (bi_ge(sb, p))
	{
		bi_release(&sb);
		bi_release(&p);
		return (actual_rounding(s, offset, digit_exponent));
	}
	bi_release(&sb);
	bi_release(&p);
	return (s);
}
