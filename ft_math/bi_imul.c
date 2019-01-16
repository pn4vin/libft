/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_imul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:22:47 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:22:49 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Big integer inplace multiplication
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_imul(t_bigint *a, t_bigint *b)
{
	t_bigint	*r;

	r = bi_mul(a, b);
	bi_replace(a, r);
	free(r);
	return (a);
}
