/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_fast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:42:39 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 20:42:40 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"
#include "ft_math.h"

static char	*rounded(char *val)
{
	int		n;
	int		v;

	n = ft_slen(val) - 1;
	while (n >= 0)
	{
		v = val[n] - '0';
		if (v >= 5)
		{
			val[n] = '0';
			if (ft_isdigit(val[n - 1]))
				val[n - 1] = (char)(val[n - 1] - '0' + 1 + '0');
			else
				val[n - 2] = (char)(val[n - 2] - '0' + 1 + '0');
		}
		else
			break ;
		n--;
	}
	return (val);
}

static void	handle_zeros(char *expanded, int *i, int fst_digit_exp)
{
	int		j;

	expanded[*i++] = '0';
	expanded[*i++] = '.';
	j = 0;
	while (++j < -fst_digit_exp)
		expanded[*i++] = '0';
}

char		*ft_dtoa(t_nbr nbr, t_spec *spec)
{
	char	*expanded;
	int		fst_digit_exp;
	int		i;
	double	v;

	expanded = ft_strnew(40);
	i = 0;
	if (nbr.d < 0)
		nbr.d *= -1.0f;
	if ((fst_digit_exp = get_digit_exponent(nbr.d)) < 0)
		handle_zeros(expanded, &i, fst_digit_exp);
	nbr.d /= ft_dpow(10, fst_digit_exp);
	while (nbr.d > 0)
	{
		v = ft_floor(nbr.d);
		expanded[i++] = (char)('0' + v);
		nbr.d -= v;
		nbr.d *= 10.0;
		if (i == fst_digit_exp + 1)
			expanded[i++] = '.';
		if (i > fst_digit_exp + 1 && i >= fst_digit_exp + 2 + spec->prec)
			break ;
	}
	return (rounded(expanded));
}
