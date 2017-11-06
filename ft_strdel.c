/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:35:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 14:35:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Free string and set pointer to it's memory location to NULL
**
** @param      as    address of a string.
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
