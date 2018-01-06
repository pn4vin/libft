/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:57:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 19:57:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Compare two strings to be identical
**
** @param      s1    String 1
** @param      s2    String 2
**
** @return     1 if two strings are identical in content, otherwise 0
*/

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 != NULL && s2 != NULL)
		return (ft_strcmp(s1, s2) == 0 ? 1 : 0);
	else
		return (0);
}
