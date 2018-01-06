/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 12:07:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/04 12:07:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      save a copy of a string
**
** @note       If allocation fails, malloc emits NULL pointer
**
** @param      s1    String to be copied
**
** @return     brand new string or NULL if allocation fails
*/

char	*ft_strdup(const char *s1)
{
	size_t	src_len;
	char	*dp;

	src_len = ft_strlen(s1) + 1;
	dp = (char *)malloc(sizeof(char) * (src_len));
	if (dp != NULL)
		ft_memcpy(dp, s1, src_len);
	return (dp);
}
