/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:57:12 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:39:18 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static t_bigint	*prepend_carry(t_bigint *r, int carry)
{
	if (carry == 0)
		return (r);
	bi_prepend_blocks(r, 1);
	r->arr[0] = carry;
	return (r);
}

/*
** @brief Big integer addition
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint		*bi_add(t_bigint *a, t_bigint *b)
{
	t_bigint	*n;
	int			carry;
	size_t		it[3];
	int			v;

	carry = 0;
	it[0] = a->size;
	it[1] = b->size;
	it[2] = it[0] > it[1] ? it[0] : it[1];
	n = bi_alloc(it[2]);
	n->sign = (a->sign + b->sign) > 0;
	while (True)
	{
		if (it[0] > 0 && it[1] > 0)
			v = a->arr[it[0]-- - 1] + b->arr[it[1]-- - 1];
		else if (it[0] > 0)
			v = a->arr[it[0]-- - 1];
		else if (it[1] > 0)
			v = b->arr[it[1]-- - 1];
		else
			break ;
		n->arr[it[2]-- - 1] = (v + carry) % SPLIT_CONST;
		carry = (v + carry) / SPLIT_CONST;
	}
	return (prepend_carry(n, carry));
}
