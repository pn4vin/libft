/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_ret.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 11:07:52 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:10:11 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** @brief      Free the memory location pointed to by <address>.
**
** @param      address  The address
**
** @return     address of the location freed.
*/

void	*ft_memrelease(void **address)
{
	ft_memdel(address);
	return (*address);
}
