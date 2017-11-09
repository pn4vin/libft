/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:11:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/09 16:45:10 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Get the length of the next word
**
** @param      str   The string
** @param      sep   The separator
**
** @return     Length of the next word
*/

static size_t		wordlen(char *str, char *sep)
{
	size_t			size;
	char			*save_sep;

	size = 0;
	save_sep = sep;
	while (*str)
	{
		sep = *str && *str != *sep ? save_sep : sep + 1;
		size++;
		if (!*sep)
		{
			size -= ft_slen(save_sep);
			break ;
		}
		str++;
	}
	return (size);
}

/*
** @brief      Generate tokens from string
**
** @param      str   The string
** @param      sep   The separator
**
** @return     First token if str != NULL. If str == NULL, return the next token
**             of the str that was passed first. If tokenizer exhausted, return
**             NULL.
*/

char				*ft_strtok(char *str, char *sep)
{
	static char		*s;
	char			*res;
	size_t			len;

	if (str != NULL)
		s = str;
	if (*s == '\0')
		return (NULL);
	len = wordlen(s, sep);
	res = ft_strnew(len);
	ft_strncpy(res, s, len);
	s = s + len;
	s += *s != '\0' ? ft_slen(sep) : 0;
	return (res);
}
