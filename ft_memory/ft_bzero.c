/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:48:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:20 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      Write n zeroes to a byte string
**
** @param      s     String s
** @param      n     # of bytes to be written to s
*/

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
