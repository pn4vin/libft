/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:57:15 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:27:09 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Convert UTF-8 string to ASCII string
**
** @param      utf8str  The utf 8 string
**
** @return     ASCII-converted string
*/

char	*ft_wcstombs(wchar_t *utf8str, int size)
{
	char	*res;
	char	*wchar;
	int		i;
	int		j;

	if (!utf8str)
		return (NULL);
	res = ft_strnew((size_t)ft_wcslen(utf8str));
	i = 0;
	while (*utf8str)
	{
		wchar = ft_wcrtomb(*utf8str++);
		j = 0;
		if (size > -1 && (i + (int)ft_slen(wchar)) > size)
		{
			free(wchar);
			break ;
		}
		while (wchar[j])
			res[i++] = wchar[j++];
		free(wchar);
	}
	return (res);
}
