/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:08:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/02 14:35:39 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Copy memory area from src to dst, up to n bytes
**
** @note       Overlapping memory regions = UB
**
** @param      dst   The destination
** @param      src   The source
** @param      n     number of bytes
**
** @return     the original value of dst (pointer to the start)
*/

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	unsigned const char	*sp;

	dp = (unsigned char *)dst;
	sp = (const unsigned char*)src;
	while (n--)
		dp[n] = sp[n];
	return (dst);
}
