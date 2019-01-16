/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_commons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 19:25:05 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/13 20:58:45 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief zero (0) in big integer format
**
** @return t_bigint*
*/

t_bigint	*bi_zero(void)
{
	t_bigint	*n;

	n = bi_alloc(1);
	return (n);
}

/*
** @brief One (1) in big integer format
**
** @return t_bigint*
*/

t_bigint	*bi_one(void)
{
	t_bigint	*n;

	n = bi_zero();
	n->arr[0] = 1;
	return (n);
}
