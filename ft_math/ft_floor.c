/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:38:03 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 20:38:43 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Simple floor (please don't use with big numbers, pretty please)
**
** @param v
** @return double
*/

double	ft_floor(double v)
{
	t_ull	convert_to;

	convert_to = (t_ull)v;
	return ((double)convert_to);
}
