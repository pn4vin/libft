/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:54:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:12 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnum.h"

/*
** @brief      Convert the initial portion of the byte string to integer
**             representation
**
**             Equivalent to (and implemented in libc as) strtol
**
** @param      str   The string
**
** @return     integer
*/

int		ft_atoi(const char *str)
{
	return ((int)ft_strtol(str, (char **)NULL, 10));
}
