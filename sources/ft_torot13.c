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

#include "libft.h"

/*
** @brief      Connvert letter to it's ROT13 representation by adress.
**
** @note       ROT13 is a reciprocal substitution cipher that gained a large
**             popularity on the Web.
**
** @param      ac    Address of the character
*/

void	ft_torot13(char *ac)
{
	char	c;

	if (ac != NULL)
	{
		c = *ac;
		if (c >= 65 && c <= 90)
			*ac = (char)((c - 65 + 13) % 26 + 65);
		else if (c >= 97 && c <= 122)
			*ac = (char)((c - 97 + 13) % 26 + 97);
	}
}
