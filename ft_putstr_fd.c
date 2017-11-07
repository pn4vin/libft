/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:33:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/07 11:33:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Output string to a file descriptor
**
** @param      s     String
** @param      fd    File Descriptor
*/

void	ft_putstr_fd(const char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}
