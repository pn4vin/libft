/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:12:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:33 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      locate a character in a string
**
** @param      s     String
** @param      c     Character (converted to unsigned char)
** @param      n     Number of bytes to be searched
**
** @return     if located, a pointer to the byte returned. Otherwise, NULL is
**             returned if no such byte exists within the first n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ps;

	ps = (const unsigned char *)s;
	while (n--)
	{
		if (*ps == (unsigned char)c)
			return ((void *)ps);
		ps++;
	}
	return (NULL);
}
