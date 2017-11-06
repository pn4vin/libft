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

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *res;

	if (s != NULL && f != NULL)
	{
		res = ft_strnew(ft_strlen(s));
		while (*s)
			*res++ = f(*s++);
		return (res);
	}
	else
		return (NULL);
}
