/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:32:37 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/06 09:32:49 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Calculate number of bytes that UTF-8 char occupies.
**
** @param      c     UTF-8 char
**
** @return     Number of bytes required to store UTF-8 char in memory
*/

size_t	ft_wcharlen(int c)
{
	if (c <= (1 << 7))
		return (1);
	else if (c <= (1 << 11))
		return (2);
	else if (c <= (1 << 16))
		return (3);
	else
		return (4);
}
