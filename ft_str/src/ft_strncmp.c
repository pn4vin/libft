/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:35:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:25:35 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Compare two null-terminated strings, not more than n characters.
**
** @param      s1    String 1
** @param      s2    String 2
** @param      n     Upper limit on the number of comparisons
**
** @return     Difference between the first pair of nonequivalent characters
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char		*p1;
	const unsigned char		*p2;
	size_t					i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && !(*p1 == 0 || *p2 == 0))
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		i++;
	}
	return (n == 0 || i == n ? 0 : *p1 - *p2);
}
