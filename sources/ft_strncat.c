/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 12:19:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:48:07 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Concatenate two string.
**
** @note       ft_strncat() appends no more than n chars from s2 to s1 and adds
**             nul-terminator at the end. The string s1 *must* have sufficient
**             space, as memcpy will *happily* write to the memory it don't own.
**
** @param      s1    String 1
** @param      s2    String 2
** @param      n     number of bytes to copy
**
** @return     Pointer to concatenated s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len_s1;
	size_t len_s2;
	size_t min;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	min = len_s2 > n ? n : len_s2;
	ft_strncpy(&s1[len_s1], s2, min);
	s1[len_s1 + min] = '\0';
	return (s1);
}
