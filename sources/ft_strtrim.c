/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:24:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:47:39 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/*
** @brief      Create new string by trimming an argument
**
** @note       Whitespaces are the following characters: ' ', '\t', '\n'
**
** @param      s     String to be trimmed
**
** @return     New, independent from the origin, trimmed string
*/

char		*ft_strtrim(const char *s)
{
	size_t		len;
	char		*res;

	if (s != NULL)
	{
		while (is_space(*s))
			s++;
		len = ft_strlen(s);
		while (len > 0 && is_space(*(s + len - 1)))
			len--;
		res = ft_strnew(len);
		return (res != NULL ? ft_strncpy(res, s, len) : NULL);
	}
	return (NULL);
}
