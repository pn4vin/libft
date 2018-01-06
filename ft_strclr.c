/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:56:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 14:56:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Set every character of the string to the value '\0'
**
** @param      s     The string that needs to be cleared
*/

void	ft_strclr(char *s)
{
	if (s != NULL)
	{
		while (*s)
			*s++ = '\0';
	}
}
