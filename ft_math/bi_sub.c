/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:24:25 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:24:57 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Subtraction
**
** @note: Assuming both numbers are positive
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_sub(t_bigint *a, t_bigint *b)
{
	t_bigint	*r;
	int			carry;
	int			it[3];

	r = bi_alloc(a->size);
	carry = 0;
	it[0] = (int)a->size;
	it[1] = (int)b->size;
	while (it[0] > 0)
	{
		if (it[1] > 0)
			it[2] = a->arr[it[0] - 1] - (b->arr[it[1] - 1] + carry);
		else
			it[2] = a->arr[it[0] - 1] - carry;
		carry = carry / SPLIT_CONST;
		if (it[2] < 0)
		{
			carry += 1;
			it[2] = SPLIT_CONST + it[2];
		}
		r->arr[it[0] - 1] = it[2];
		it[0]--;
		it[1]--;
	}
	return (shrink_to_fit(r));
}
