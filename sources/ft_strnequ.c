/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:13:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 20:13:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Lexicographical comparison between s1 and s2 up to n chars or
**             until \0 reached.
**
** @param      s1    String 1
** @param      s2    String 2
** @param      n     Number of pairs to be compared
**
** @return     1 if strings are identical up to n chars, otherwise 0
*/

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
		return (ft_strncmp(s1, s2, n) == 0 ? 1 : 0);
	else
		return (0);
}
