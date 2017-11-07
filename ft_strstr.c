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
** @param      big     String to be searched
** @param      little  Substring to be located
**
** @return     pointer to the substring matched.
*/

char	*ft_strstr(const char *big, const char *little)
{
	int			i;
	int			j;
	int			next;

	if (!(*big) && !(*little))
		return ((char *)big);
	i = 0;
	j = 0;
	next = 0;
	while (big[i] != '\0')
	{
		next = i;
		j = 0;
		while (big[i] && little[j] && (big[i] == little[j]))
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return (&((char *)big)[next]);
		i = next + 1;
	}
	return (NULL);
}
