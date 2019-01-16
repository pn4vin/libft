/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:58:14 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 20:58:55 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_memory.h"

/*
** @brief Duplicate first <n> characters from the string
**
** @param s String
** @param n # of characters to copy
** @return char <Fresh> (sub)string
*/

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*r;

	i = 0;
	if (n >= ft_slen(s))
		n = ft_slen(s);
	r = ft_strnew(n);
	while (i < n)
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}
