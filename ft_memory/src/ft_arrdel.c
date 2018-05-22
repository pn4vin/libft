/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:58:45 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/03/09 16:43:59 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** Free all elements of an array.
** @param ap Address of an array
*/

void	ft_arrdel(void **ap)
{
	void	**tmp;

	while (*ap)
	{
		tmp = ap + 1;
		ft_memdel(ap);
		ap = tmp;
	}
	ft_memdel(ap);
}
