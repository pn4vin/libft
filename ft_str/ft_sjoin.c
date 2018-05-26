/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sjoin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:12:50 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:23:56 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include <stdarg.h>

/*
** @brief      Concatenate nul-terminated strings
**
**             If <cnt> and number of arguments differ, behavior is undefined.
** @param      cnt        The number of strings to be concatenated
** @param      ellipses   Strings to be concatenated
**
** @return     New string, the result of concatenation in the order provided
*/

char	*ft_sjoin(int cnt, ...)
{
	char	*ptrs[cnt];
	va_list	args;
	int		i;
	int		len;
	char	*concatenated;

	va_start(args, cnt);
	i = 0;
	len = 0;
	while (i < cnt)
	{
		ptrs[i] = va_arg(args, char *);
		len += ft_slen(ptrs[i++]);
	}
	va_end(args);
	concatenated = len > 0 ? ft_strnew(len) : NULL;
	i = 0;
	while (i < cnt)
		ft_strcpy(concatenated + ft_slen(concatenated), ptrs[i++]);
	return (concatenated);
}
