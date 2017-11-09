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
** @param      haystack     Container string
** @param      needle       Substring to search
** @param      len       upper limit on the number of character pairs to be
**                     checked
**
** @return     Pointer to the first character of the first occurrence of a
**             substring. If little is NULL, return whole container string.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			save_i;
	const char		*hay_p;
	const char		*needle_p;

	if (*needle == '\0')
		return ((char*)haystack);
	needle_p = needle;
	i = 0;
	while (i < len && *haystack)
	{
		hay_p = haystack;
		save_i = i;
		while (*haystack && *needle_p && *haystack == *needle_p && i++ < len)
		{
			haystack++;
			needle_p++;
		}
		if (!*needle_p && i <= len)
			return ((char *)hay_p);
		haystack = hay_p + 1;
		needle_p = needle;
		i = save_i + 1;
	}
	return (NULL);
}
