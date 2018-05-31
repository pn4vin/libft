/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:36:33 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/05/31 21:36:48 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

int		ft_strcnt(char *str, char c)
{
	int	cnt;

	cnt = 0;
	if (str)
		while (*str)
		{
			if (*str == c)
				cnt++;
			str++;
		}
	return (cnt);
}
