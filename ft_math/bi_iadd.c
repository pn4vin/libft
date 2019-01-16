/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_iadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:39:08 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:39:22 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Inplace addition. Results are stored in the first operand.
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_iadd(t_bigint *a, t_bigint *b)
{
	t_bigint	*n;

	n = bi_add(a, b);
	bi_replace(a, n);
	free(n);
	return (a);
}
