/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_mul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:24:09 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:24:10 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Big integer multiplication
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_mul(t_bigint *a, t_bigint *b)
{
	t_bigint	*n;
	size_t		i;
	t_bigint	*tmp1;
	int			val;

	n = bi_zero();
	n->sign = (a->sign + b->sign) % 2;
	i = 0;
	while (i < b->size)
	{
		val = b->arr[b->size - (i + 1)];
		bi_ishift10((tmp1 = bi_cmul(a, val % 10)), (int)(i * 3));
		bi_iadd(n, tmp1);
		bi_release(&tmp1);
		bi_ishift10((tmp1 = bi_cmul(a, val / 10 % 10)), (int)(i * 3 + 1));
		bi_iadd(n, tmp1);
		bi_release(&tmp1);
		bi_ishift10((tmp1 = bi_cmul(a, val / 100)), (int)(i * 3 + 2));
		bi_iadd(n, tmp1);
		bi_release(&tmp1);
		i++;
	}
	return (n);
}
