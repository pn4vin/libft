/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:30:01 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:31:21 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	m;
	char	tmp;

	i = 0;
	m = ft_slen(str);
	while (i < m / 2)
	{
		tmp = str[i];
		str[i] = str[m - 1 - i];
		str[m - 1 - i] = tmp;
		i++;
	}
	return (str);
}
