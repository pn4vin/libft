/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoutf8.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 18:51:01 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:26:52 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Convert narrow string to a multibyte sequence
**
** @param      str   The string
**
** @return     The wchar_t *string
*/

wchar_t	*ft_strtoutf8(char *str)
{
	wchar_t *res;
	int		i;

	if (!str)
		return ((wchar_t *)str);
	i = 0;
	MALLCHECK((res = (wchar_t *)malloc(sizeof(wchar_t) * (ft_slen(str) + 1))));
	while (str && *str)
		res[i++] = *str++;
	res[i] = '\0';
	return (res);
}
