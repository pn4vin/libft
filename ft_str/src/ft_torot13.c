/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_torot13.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:45:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/09 16:51:50 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Connvert string to it's ROT13 representation.
**
** @note       ROT13 is a reciprocal substitution cipher that gained a large
**             popularity on the Web.
**
** @param      ac    New substituted string.
*/

char	*ft_strtorot13(char *ac)
{
	char	*res;
	int		i;

	res = ac ? ft_strnew(ft_slen(ac)) : NULL;
	if (ac != NULL)
	{
		i = 0;
		while (*ac)
		{
			if (*ac >= 65 && *ac <= 90)
				res[i] = (char)((*ac - 65 + 13) % 26 + 65);
			else if (*ac >= 97 && *ac <= 122)
				res[i] = (char)((*ac - 97 + 13) % 26 + 97);
			else
				res[i] = *ac;
			i++;
			ac++;
		}
	}
	return (res);
}
