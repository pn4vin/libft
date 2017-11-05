/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 22:58:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/02 22:58:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int				i;

	i = 0;
	dest_ptr = (unsigned char *)dst;
	src_cpy = (unsigned char *)malloc(sizeof(char) * len);
	while (i < len)
		src_cpy[i++] = *(unsigned char *)src++;
	i = 0;
	while (i < len)
		*dest_ptr++ = src_cpy[i++];
	free(src_cpy);
	return (dst);
}
