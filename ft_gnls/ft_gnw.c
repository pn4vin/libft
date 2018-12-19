/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:18:04 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/12/19 13:08:30 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnls.h"
#include "ft_str.h"

/*
** Get Next Word
*/

int	ft_gnw(int fd, char **word)
{
	static char	**words;
	static char	*line;
	static int	ret;
	static int	i;

	if (line == NULL && !words)
	{
		while ((ret = ft_sgnl(fd, &line)) > 0 && ft_slen(line) == 0)
			;
		if (ret == 1)
			words = ft_splitspace(line);
		else
			return (ret);
		ft_memdel((void **)&line);
		i = 0;
	}
	while (words[i])
	{
		*word = words[i++];
		return (1);
	}
	ft_memdel((void **)&words);
	return (ft_gnw(fd, word));
}
