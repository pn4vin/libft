/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:39:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/04 19:39:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Locate the last character in a string
**
** @param      s     String
** @param      c     character
**
** @return     Position of the last matching character
*/

char	*ft_strrchr(const char *s, int c)
{
	int	pos;
	int	i;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	pos = s[i] == (char)c ? i : pos;
	return (pos == -1 ? NULL : (char *)&s[pos]);
}
