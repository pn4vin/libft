/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_is_divisible.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:22:51 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:23:11 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Check if integer is divisible by <n>
**
** @param b
** @param n
** @return bool
*/

t_bool	is_divisible(t_bigint *b, int n)
{
	return (b->arr[b->size - 1] % n == 0);
}
