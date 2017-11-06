/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:09:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/02 14:26:55 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Copy src to dest until char found, up to n bytes
**
** @param      dst   The destination
** @param      src   The source
** @param      c     char to locate (converted to unsigned)
** @param      n     n bytes
**
** @return     if c occurs in the string src, the copy stops and a pointer to
**             the byte after the copy of c is returned. Otherwise, n bytes are
**             copied, and a NULL pointer is returned.
*/

void		*ft_memccpy_test(void *dst, const void *src, int c, size_t n)
{
	char		*dp;
	const char	*sp;

	sp = (const char *)src;
	dp = (char *)dst;
	while (n--)
	{
		if (*sp == (unsigned char)c)
		{
			*dp++ = *sp;
			return (dp);
		}
		*dp++ = *sp++;
	}
	return (NULL);
}
