/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_comparisons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:48:50 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:21:11 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Greater then
**
** @param a
** @param b
** @return t_bool
*/

t_bool	bi_gt(t_bigint *a, t_bigint *b)
{
	size_t	i;

	if (a->sign != b->sign)
		return (a->sign < b->sign);
	if (a->size != b->size)
		return (a->sign ? a->size < b->size : a->size > b->size);
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] == b->arr[i])
			i++;
		else
			return (a->sign ? a->arr[i] < b->arr[i] : a->arr[i] > b->arr[i]);
	}
	return (False);
}

/*
** @brief Equal
**
** @param a
** @param b
** @return t_bool
*/

t_bool	bi_eq(t_bigint *a, t_bigint *b)
{
	size_t	i;

	if (a->sign != b->sign || a->size != b->size)
		return (False);
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] != b->arr[i])
			return (False);
		i++;
	}
	return (True);
}

/*
** @brief Greater or equal
**
** @param a
** @param b
** @return t_bool
*/

t_bool	bi_ge(t_bigint *a, t_bigint *b)
{
	size_t	i;

	if (a->sign != b->sign)
		return (a->sign < b->sign);
	if (a->size != b->size)
		return (a->sign ? a->size < b->size : a->size > b->size);
	i = 0;
	while (i < a->size)
	{
		if (a->arr[i] == b->arr[i])
			i++;
		else
			return (a->sign ? a->arr[i] < b->arr[i] : a->arr[i] > b->arr[i]);
	}
	return (True);
}

/*
** @brief Less then
**
** @param a
** @param b
** @return t_bool
*/

t_bool	bi_lt(t_bigint *a, t_bigint *b)
{
	return (!bi_ge(a, b));
}

/*
** @brief Less or equal
**
** @param a
** @param b
** @return t_bool
*/

t_bool	bi_le(t_bigint *a, t_bigint *b)
{
	return (!bi_gt(a, b));
}
