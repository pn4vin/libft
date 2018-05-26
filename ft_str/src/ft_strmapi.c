/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:37:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:25:28 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Create a new string by applying indexed function to a template
**             string
**
** @param      s     String template
** @param      f     Function to be applied
**
** @return     New string where each character is the result of f function call
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			srclen;
	char			*res;

	i = 0;
	if (s != NULL && f != NULL)
	{
		srclen = ft_strlen(s);
		if ((res = ft_strnew(srclen)) == NULL)
			return (NULL);
		while (s[i])
		{
			res[i] = f(i, s[i]);
			i++;
		}
		return (res);
	}
	else
		return (NULL);
}
