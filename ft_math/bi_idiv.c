/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_idiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:22:36 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:22:45 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Inplace division
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_idiv(t_bigint *a, t_bigint *b)
{
	t_bigint	*r;

	r = bi_div(a, b);
	bi_replace(a, r);
	free(r);
	return (a);
}
