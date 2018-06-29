/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strispaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 19:29:57 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/06/09 19:35:50 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief Check if string is either (1) empty or (2) contains only
**        space-like characters.
**
**             White-space character set comprises:
**
**             ASCII  |  Name
**
**             32     |  space
**             09     |  horizontal tab
**             10     |  line feed
**             11     |  vertical tab
**             12     |  form feed
**             13     |  carriage return
**
** @param str String to be tested
** @return True if string contains only space characters, otherwise False
*/

t_bool	ft_strispaces(char *str)
{
	if (!str)
		return (False);
	while (*str)
		if (!ft_isspace(*str++))
			return (False);
	return (True);
}
