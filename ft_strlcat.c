/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:31:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/05 15:53:14 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** @brief      Size-bounded string concatenation
**
** @note dstsize should include space for nul-terminator
**
** @param      dst      The destination
** @param      src      The source
** @param      dstsize  The dstsize
**
** @return     The total size of a string tried to create
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		len_dst;
	size_t		len_src;
	size_t		src_i;

	len_dst = 0;
	len_src = ft_strlen(src);
	while (dst[len_dst] != '\0' && len_dst < dstsize)
		len_dst++;
	if (len_dst >= dstsize)
		return (len_dst + len_src);
	src_i = 0;
	while (*src)
	{
		if (src_i < dstsize - len_dst - 1)
			dst[len_dst + src_i++] = *src;
		src++;
	}
	dst[len_dst + src_i] = '\0';
	return (len_dst + len_src);
}
