/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:35:45 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:16 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      convert ASCII string to long integer
**
**             equivalent to (and implemented in libc as): strtol(str, (char
**             **)NULL, 10)
**
** @param      str   The string
**
** @return     long integer representation of the number written in the string
*/

long int	ft_atol(const char *str)
{
	return (ft_strtol(str, (char **)NULL, 10));
}
