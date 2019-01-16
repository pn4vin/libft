/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_div.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:21:48 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:22:26 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static t_bigint	*div_checks(t_bigint *a, t_bigint *b)
{
	if (bi_lt(a, b))
		return (bi_zero());
	else if (bi_eq(a, b))
		return (bi_one());
	else if (bi_ceq(b, 1))
		return (bi_copy(a));
	else
		return (NULL);
}

static void		optimized_subtraction(t_bigint *a_cp, t_bigint *b, t_bigint *r)
{
	t_bigint	*divisor;
	t_bigint	*scaler;
	size_t		i;

	i = 10;
	scaler = bi_one();
	bi_append_blocks(scaler, i);
	while (i > 0)
	{
		divisor = bi_mul(b, scaler);
		if (bi_ceq(divisor, 0))
		{
			bi_release(&divisor);
			break ;
		}
		while (bi_ge(a_cp, divisor))
		{
			bi_isub(a_cp, divisor);
			bi_iadd(r, scaler);
		}
		bi_end_cut(scaler, 1);
		bi_release(&divisor);
		i--;
	}
	bi_release(&scaler);
}

/*
** @brief Division
**
** @note Assume both are positive
** @param a
** @param b
** @return t_bigint*
*/

t_bigint		*bi_div(t_bigint *a, t_bigint *b)
{
	t_bigint	*r;
	t_bigint	*tmp;

	if ((r = div_checks(a, b)))
		return (r);
	r = bi_zero();
	tmp = bi_copy(a);
	optimized_subtraction(tmp, b, r);
	while (bi_ge(tmp, b))
	{
		bi_isub(tmp, b);
		bi_increment(r);
	}
	bi_release(&tmp);
	return (r);
}
