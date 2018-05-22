/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:56:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:25:39 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_memory.h"

/*
** @brief      Copy first len character from src to dst
**
** @param      dst   The destination
** @param      src   The source
** @param      len   The length
**
** @return     pointer to dst
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	ft_memcpy(dst, src, len);
	if (srclen < len)
		while (srclen < len)
			dst[srclen++] = '\0';
	return (dst);
}
