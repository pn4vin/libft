/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 23:27:30 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/16 23:27:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bigint	*init_num(int exponent, t_ull mantissa, int digit_exponent)
{
	t_bigint	*num;
	t_bigint	*tmp;
	t_bigint	*two;

	num = bi_utobi(mantissa);
	if (exponent > 0)
	{
		two = bi_utobi(2);
		tmp = bi_pow(two, exponent);
		bi_imul(num, tmp);
		bi_release(&tmp);
		bi_release(&two);
	}
	if (digit_exponent < 0)
		bi_ishift10(num, -digit_exponent);
	return (num);
}

static t_bigint	*init_denom(int exponent)
{
	t_bigint	*denom;
	t_bigint	*tmp;

	if (exponent > 0)
		return (bi_one());
	tmp = bi_utobi(2);
	denom = bi_pow(tmp, -exponent);
	bi_release(&tmp);
	return (denom);
}

t_bigint		*bintodec2(double d, int exponent, t_ull mantissa)
{
	t_bigint	*res;
	t_bigint	*num;
	t_bigint	*denom;
	t_bigint	*zero;
	t_bigint	*r;

	res = bi_zero();
	zero = bi_zero();
	exponent -= 52;
	num = init_num(exponent, mantissa, d != 0 ? get_digit_exponent(d) : 0);
	denom = init_denom(exponent);
	while (bi_gt(num, zero))
	{
		r = bi_div(num, denom);
		bi_ishift10(res, 1);
		bi_iadd(res, r);
		bi_isub(num, bi_imul(r, denom));
		bi_ishift10(num, 1);
		bi_release(&r);
	}
	bi_release(&num);
	bi_release(&denom);
	bi_release(&zero);
	return (res);
}

t_bigint		*float_convert(double d)
{
	int			sign;
	int			exponent;
	t_ull		mantissa;
	t_bigint	*repr;

	extract_info(d, &sign, &exponent, &mantissa);
	preprocess(&exponent, &mantissa);
	if (d < 0)
		d *= -1;
	repr = bintodec2(d, exponent, mantissa);
	repr->sign = sign;
	return (repr);
}
