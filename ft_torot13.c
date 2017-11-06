/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot13.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:45:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 15:45:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Connvert letter to it's ROT13 representation by adress.
**
** @note  ROT13 is a reciprocal substitution cipher
**
** @param      s     { parameter_description }
*/

void	ft_torot13(char *s)
{
	char	c;

	if (s != NULL)
	{
		c = *s;
		if (c >= 65 && c <= 90)
			*s = (char)((c - 65 + 13) % 26 + 65);
		else if (c >= 97 && c <= 122)
			*s = (char)((c - 97 + 13) % 26 + 97);
	}
}
