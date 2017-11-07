/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:37:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/01 17:23:57 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Find substring in a string, up to n characters
**
** @param      big     Container string
** @param      little  Substring to search
** @param      n       upper limit on the number of character pairs to be
**                     checked
**
** @return     Pointer to the first character of the first occurrence of a
**             substring. If little is NULL, return whole container string.
*/

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t			i;
	size_t			j;
	const char		*substr_start;

	substr_start = big;
	i = 0;
	j = 0;
	if (little && *little == '\0')
		return ((char*)substr_start);
	while (i < n && big[i] && little[j])
	{
		if (big[i] == little[j])
			substr_start = j == 0 ? &big[i] : substr_start;
		else
			substr_start = NULL;
		j = big[i++] == little[j] ? j + 1 : 0;
	}
	return (j < ft_strlen(little) || j == 0 ? NULL : (char *)substr_start);
}
