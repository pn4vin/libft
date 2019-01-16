/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_isub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:23:13 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:23:21 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_memory.h"

/*
** @brief Inplace subtraction
**
** @param a
** @param b
** @return t_bigint*
*/

t_bigint	*bi_isub(t_bigint *a, t_bigint *b)
{
	t_bigint	*r;

	r = NULL;
	r = bi_sub(a, b);
	bi_replace(a, r);
	ft_memdel((void **)&r);
	return (a);
}
