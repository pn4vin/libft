/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:26:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/04 20:26:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Concatenate two strings
**
** @param      s1    String 1
** @param      s2    String 2
**
** @return     Concatenated first string
*/

char	*ft_strcat(char *s1, const char *s2)
{
	size_t		s1_len;
	size_t		s2_len;

	s1_len = ft_slen(s1);
	s2_len = ft_slen(s2);
	s1[s1_len + s2_len] = '\0';
	while (s2_len--)
		s1[s1_len + s2_len] = s2[s2_len];
	return (s1);
}
