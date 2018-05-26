/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 21:11:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/12 08:36:18 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Create a new string my merging <s2> to the end of <s1>
**
** @param      s1    String 1
** @param      s2    String 2
**
** @return     New, independent string, which is the result of concatenation of
**             s1 ans s2
*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;

	res = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		res = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (res != NULL)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
		}
	}
	return (res);
}
