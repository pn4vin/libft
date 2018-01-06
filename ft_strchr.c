/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:50:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/04 18:50:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Locate character in string
**
** @param      s     String
** @param      c     Integer representing unsigned char
**
** @return     pointer to the first located character, or NULL if the character
**             does not appear in the string
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (*s == (char)c ? (char *)s : NULL);
}
