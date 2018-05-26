/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:08:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:39 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      Copy ft_memory area from src to dst, up to n bytes
**
** @note       Overlapping ft_memory regions = UB
**
** @param      dst   The destination
** @param      src   The source
** @param      n     number of bytes
**
** @return     the original value of dst (pointer to the start)
*/

void		*ft_memcpy_fwd(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	unsigned const char	*sp;
	size_t				i;

	dp = (unsigned char *)dst;
	sp = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dst);
}
