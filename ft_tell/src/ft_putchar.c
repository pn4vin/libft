/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:52:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:19:53 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tell.h"

/*
** @brief      Put char to standard output
**
** @param      c     Char
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}
