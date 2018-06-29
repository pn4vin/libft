/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 16:29:07 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/09 16:33:55 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Check if string starts with some prefix
**
** @param      str     The string
** @param      prefix  The prefix
**
** @return     True if string contains prefix, otherwise false
*/

t_bool		ft_startswith(const char *str, char *prefix)
{
	if (!str || !prefix)
		return (False);
	while (*prefix)
	{
		if (*str++ != *prefix++)
			return (False);
	}
	return (True);
}
