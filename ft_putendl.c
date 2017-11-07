/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:29:12 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/07 13:30:19 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Output string s to stdout followed by a '\n' character
**
** @param      s     String
*/

void	ft_putendl(const char *s)
{
	ft_putendl_fd(s, 1);
}
