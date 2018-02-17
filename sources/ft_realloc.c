/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:53:53 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/16 18:59:58 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Realloc new memory location and copy <memloc> there
**
**
** @note       if <new_size> is smaller than <old_size>, only <new_size> bytes
**             from <memloc> pointer location are copied
** @param      memloc          The memloc
** @param      memloc_size     The memloc size
** @param      newmemloc_size  The newmemloc size
**
** @return     New memory location of size <newmemloc_size>
*/

void	*ft_realloc(void *memloc, size_t old_size, size_t new_size)
{
	void	*newmemloc;

	MALLCHECK((newmemloc = malloc(new_size)));
	ft_memcpy(newmemloc, memloc, old_size < new_size ? old_size : new_size);
	return (newmemloc);
}
