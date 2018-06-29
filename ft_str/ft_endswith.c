/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:05:44 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/23 15:38:30 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Check whether <str> ends with the <suffix> provided
**
** @param      str     String to look into
** @param      suffix  The suffix
**
** @return     True if <str> contains the given <suffix>, otherwise False
*/

t_bool	ft_endswith(const char *str, char *suffix)
{
	size_t	suf_len;
	size_t	s_len;
	int		i;

	suf_len = ft_slen(suffix);
	s_len = ft_slen(str);
	i = 0;
	if (suf_len > s_len)
		return (False);
	while (suf_len > 0)
	{
		if (suffix[suf_len - 1] != str[s_len - (i + 1)])
			return (False);
		suf_len--;
		i++;
	}
	return (True);
}
