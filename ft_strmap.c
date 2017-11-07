/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:07:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 17:07:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Map function to the *fresh* string
**
** @param      s     String template
** @param      f     Function to be applied
**
** @return     New string, each char of which is a result of f function call
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	srclen;
	char	*res;

	if (s != NULL && f != NULL)
	{
		srclen = ft_strlen(s);
		if ((res = ft_strnew(srclen)) == NULL)
			return (NULL);
		while (*s)
			*res++ = f(*s++);
		return (res - srclen);
	}
	else
		return (NULL);
}
