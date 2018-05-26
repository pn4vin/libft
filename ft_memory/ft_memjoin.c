/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 19:06:22 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:50:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      Join two ft_memory locations together
**
** @param      m1      The m1
** @param      m1_len  The m1 length
** @param      m2      The m2
** @param      m2_len  The m2 length
**
** @return     Pointer to the new ft_memory location with arguments concatenated.
*/

void	*ft_memjoin(void *m1, size_t m1_len, void *m2, size_t m2_len)
{
	void	*joined;

	joined = malloc(m1_len + m2_len);
	ft_memcpy(joined, m1, m1_len);
	ft_memcpy(joined + m1_len, m2, m2_len);
	free(m1);
	return (joined);
}
