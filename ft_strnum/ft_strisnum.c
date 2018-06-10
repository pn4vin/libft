/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:15:30 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/26 18:18:13 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** Check if the given string is a valid number in the given base
**
** @param str   String containing number
** @param base  integer value of the radix
** @return      TRUE if string is a valid number in the given base,
**              otherwise FALSE
*/

t_bool	ft_strisnum(char *str, size_t base)
{
	static char	*radix = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int			i;
	int			found;

	if (!str)
		return (FALSE);
	if (*str == '-' && ft_slen(str) > 1)
		str++;
	while (*str)
	{
		found = -1;
		i = 0;
		while (i < 36)
			if (radix[i++] == *str)
				found = i - 1;
		if (found == -1 || (size_t)found >= base)
			return (FALSE);
		str++;
	}
	return (TRUE);
}
