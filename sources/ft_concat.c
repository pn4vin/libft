/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 08:36:12 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/12 08:39:49 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Concatenate two strings, freeing them optionally
**
** @param      s1       String 1
** @param      s2       String 2
** @param      and_free whether operand strings should be free'd or not
**
** @return     New, independent string, which is the result of concatenation of
**             s1 ans s2
*/

char	*ft_concat(char *s1, char *s2, t_bool and_free)
{
	char	*res;

	res = NULL;
	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 != NULL)
			res = ft_strdup(s2);
		else if (s2 == NULL && s1 != NULL)
			res = ft_strdup(s1);
	}
	else
	{
		if ((res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) != NULL)
		{
			ft_strcpy(res, s1);
			ft_strcat(res, s2);
		}
	}
	if (and_free)
	{
		free(s1);
		free(s2);
	}
	return (res);
}
