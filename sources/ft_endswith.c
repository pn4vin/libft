/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:05:44 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/11 19:09:58 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_endswith(const char *s, char *suffix)
{
	size_t	suf_len;
	size_t	s_len;
	int		i;

	suf_len = ft_slen(suffix);
	s_len = ft_slen(s);
	i = 0;
	while (suf_len > 0)
	{
		if (suffix[suf_len - 1] != s[s_len - (i + 1)])
			return (FALSE);
		suf_len--;
		i++;
	}
	return (TRUE);
}
