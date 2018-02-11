/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:32:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/01 18:48:33 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Fill a byte string with a byte value
**
** @param      b     String b
** @param      c     Converted to an unsigned char
** @param      len   # of bytes to be written
**
** @return     Modified string
*/

void	*ft_memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (len--)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}
