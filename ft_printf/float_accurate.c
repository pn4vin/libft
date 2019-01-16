/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_accurate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:45:36 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 20:45:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_strnum.h"
#include "ft_math.h"
#include "ft_str.h"

char		*prepend_zeros(char *s, int digit_exponent)
{
	char	*r;
	size_t	i;
	size_t	len;
	int		offset;

	if (digit_exponent >= -1)
		return (s);
	len = ft_slen(s);
	r = malloc(sizeof(char) * (-digit_exponent + len + 1));
	i = 0;
	if (s[i] == '-')
		r[i++] = '-';
	offset = 0;
	while (offset < -digit_exponent - 1)
		r[i + offset++] = '0';
	while (i < len)
	{
		r[offset + i] = s[i];
		i++;
	}
	free(s);
	r[offset + i] = '\0';
	return (r);
}

char		*compose_string(char *s, int digit_exponent, int prec)
{
	char		*expanded;
	int			i;

	expanded = NULL;
	i = -1;
	if (digit_exponent < 0)
		expanded = ft_strappend(expanded, '0');
	while (++i <= digit_exponent)
		expanded = ft_strappend(expanded, *s++);
	if (prec > 0)
		expanded = ft_strappend(expanded, '.');
	i = 0;
	while (*s && i < prec)
	{
		expanded = ft_strappend(expanded, *s++);
		i++;
	}
	while (i < prec)
	{
		expanded = ft_strappend(expanded, '0');
		i++;
	}
	return (expanded);
}

char		*fp_format(t_nbr nbr, t_spec *spec)
{
	t_bigint	*repr;
	char		*s;
	char		*expanded;
	int			digit_exponent;
	char		*tmp;

	if (nbr.d < 0 || nbr.d == -0.0)
		nbr.d *= -1;
	if (nbr.d == 0)
		digit_exponent = 0;
	else
		digit_exponent = get_digit_exponent(nbr.d);
	repr = float_convert(nbr.d);
	s = prepend_zeros(bi_tostr(repr), digit_exponent);
	s = d_round(s, &digit_exponent, (size_t)spec->prec);
	tmp = s;
	expanded = compose_string(s, digit_exponent, spec->prec);
	bi_release(&repr);
	ft_strdel(&tmp);
	return (expanded);
}
