/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:47:20 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:47:52 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Truncate string if len provided is less than len(str)
**             Optionally, free the input string.
** @param      str   The string
** @param      len   The length
**
** @return     Truncated string
*/

char	*ft_strtrunc(char *str, size_t len, t_bool and_free)
{
	char	*trunc;

	if (ft_slen(str) < len)
		return (str);
	else
	{
		trunc = ft_strnew(len);
		ft_strncpy(trunc, str, len);
		if (and_free)
			free(str);
		return (trunc);
	}
}
