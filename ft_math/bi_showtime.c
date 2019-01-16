/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showtime.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:38:49 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/13 16:28:14 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_memory.h"

/*
** @brief Convert big integer to decimal string representation
**
** @param bi
** @return char*
*/

char	*bi_tostr(t_bigint *bi)
{
	char	*s;
	size_t	i;
	size_t	j;
	int		v;

	j = sizeof(char) * (bi->size) * 3 + bi->sign + 1;
	s = (char *)malloc(j);
	ft_bzero(s, j);
	j = 0;
	if (bi->sign)
		s[j++] = '-';
	i = 0;
	while (i < bi->size)
	{
		v = bi->arr[i];
		if (i > 0 || (i == 0 && v / 100 != 0))
			s[j++] = (char)('0' + v / 100);
		if (i > 0 || (v / 10 > 0))
			s[j++] = (char)('0' + v / 10 % 10);
		s[j++] = (char)('0' + v % 10);
		i++;
	}
	return (s);
}
