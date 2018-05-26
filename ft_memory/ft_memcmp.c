/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:37:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:36 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      Compare two byte strings
**
** @note       Both strings are assumed to be n bytes.
** Zero length strings are always identical
**
** @param      s1    String 1
** @param      s2    String 2
** @param      n     number of bytes to compare
**
** @return     { description_of_the_return_value }
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1p;
	unsigned char	*s2p;
	size_t			i;

	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	i = 0;
	while (i < n && s1p[i] == s2p[i])
		i++;
	return (i == n ? 0 : s1p[i] - s2p[i]);
}
