/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:58:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:47 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief Copy len bytes from string src to string dst
**
** @note The two strings may overlap; the copy is always done in non-destructive
** manner
** @param dst Destination location
** @param src Source location
** @param len Number of bytes to be copied
** @return pointer to the original dst
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_cpy;
	size_t			i;

	dest_ptr = (unsigned char *)dst;
	src_cpy = (unsigned char *)src;
	if (src < dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = 0;
		while (i < len)
		{
			dest_ptr[i] = src_cpy[i];
			i++;
		}
	}
	return (dst);
}
