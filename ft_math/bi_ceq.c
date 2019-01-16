/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_ceq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 22:15:37 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/16 22:16:40 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Check if big integer is equal to regular one
**
** @param a big integer
** @param b integer to compare to
** @return t_bool True if equal, otherwise False
*/

t_bool	bi_ceq(t_bigint *a, int b)
{
	if (a->size != 1 || a->arr[0] != b)
		return (False);
	return (True);
}
