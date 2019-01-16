/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:38:37 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/13 16:31:55 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Calculate # of blocks required to store unsigned value
**
** @param v
** @return size_t
*/

size_t		bi_usize(unsigned long long v)
{
	size_t	i;

	i = 0;
	if (v == 0)
		return (1);
	while (v > 0)
	{
		v /= SPLIT_CONST;
		i++;
	}
	return (i);
}

/*
** @brief Calculate # of blocks required to store signed value
**
** @param v
** @return size_t
*/

size_t		bi_isize(long long v)
{
	size_t	i;

	i = 0;
	if (v == 0)
		return (1);
	while (v != 0)
	{
		v /= SPLIT_CONST;
		i++;
	}
	return (i);
}

/*
** @brief Calculate # of blocks required to store double-precision value
**
** @param v
** @return size_t
*/

size_t		bi_dsize(double v)
{
	size_t		i;

	i = 0;
	if (ft_fabs(v) < FP_EPS)
		return (1);
	if (v < 0)
		v *= -1.0;
	while (v > 1)
	{
		v /= SPLIT_CONST;
		i++;
	}
	return (i);
}

/*
** @brief Calculate # of places occupied in block
**
** @param b Block
** @return size_t
*/

size_t		bi_block_size(int b)
{
	size_t	i;

	i = 0;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		b /= 10;
		i++;
	}
	return (i);
}
