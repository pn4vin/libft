/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:29:14 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 20:29:16 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_math.h"

int		get_digit_exponent(double d)
{
	int		i;

	i = 0;
	if (d > 1)
	{
		while (d > 1)
		{
			d /= 10;
			i++;
		}
		if (ft_fabs(d - 1) > FP_EPS)
			i -= 1;
	}
	else
	{
		while (d < 1)
		{
			d *= 10;
			i--;
		}
	}
	return (i);
}

void	extract_info(double d, int *sign, int *exponent, t_ull *mantissa)
{
	t_nbr	nb;

	nb.d = d;
	*sign = (int)(nb.u >> 63);
	*exponent = (int)((nb.u >> 52) & 0x7FF);
	*mantissa = nb.u & 0x1FFFFFFFFFFFFF;
}

void	preprocess(int *exponent, t_ull *mantissa)
{
	if (*exponent != 0)
	{
		*exponent -= 1023;
		*mantissa |= 0x10000000000000;
	}
	else
		*exponent = -1022;
}
