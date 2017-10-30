/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:54:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 23:14:05 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
