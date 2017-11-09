/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:37:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/01 17:26:12 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Locate the first occurence of the little string in a big string
**
** @param      haystack     String to be searched
** @param      needle     Substring to be located
**
** @return     pointer to the substring matched.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	int			j;
	int			next;

	if (!(*haystack) && !(*needle))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		next = i;
		j = 0;
		while (haystack[i] && needle[j] && (haystack[i] == needle[j]))
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return (&((char *)haystack)[next]);
		i = next + 1;
	}
	return (NULL);
}
