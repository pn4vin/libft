/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:42:05 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 18:42:07 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static t_bigint		*prepand_carry(t_bigint *r, long long carry)
{
	while (carry != 0)
	{
		bi_prepend_blocks(r, 1);
		r->arr[0] = (int)(carry % SPLIT_CONST);
		carry /= SPLIT_CONST;
	}
	return (r);
}

/*
** @brief Multiply integer by a constant
**
** Although it's tempting to multiply by a large number, please use
** bi_mul instead.
** This routine is actually part of it ;)
** @param a big integer
** @param n constant
** @return t_bigint* result
*/

t_bigint			*bi_cmul(t_bigint *a, long long n)
{
	t_bigint	*r;
	long long	carry;
	size_t		i;
	long long	v;

	if (n == 0)
		return (bi_zero());
	carry = 0;
	i = a->size;
	r = bi_alloc(a->size);
	r->sign = a->sign;
	if (n < 0)
	{
		r->sign = 1;
		n *= -1;
	}
	while (i > 0)
	{
		v = a->arr[i - 1] * n;
		r->arr[i - 1] = (int)((v + carry) % SPLIT_CONST);
		carry = (v + carry) / SPLIT_CONST;
		i--;
	}
	return (prepand_carry(r, carry));
}
