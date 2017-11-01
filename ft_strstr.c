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
	const char	*substr_start;

	substr_start = NULL;
	i = 0;
	j = 0;
	while (big[i] && little[j])
	{
		if (big[i] == little[j])
			substr_start = j == 0 ? &big[i] : substr_start;
		else
			substr_start = NULL;
		j = big[i++] == little[j] ? j + 1 : 0;
	}
	return (ft_strlen(little) == 0 ? (char *)big : (char *)substr_start);
}
