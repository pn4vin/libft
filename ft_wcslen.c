/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:32:10 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/06 09:32:21 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Calculate length of UTF-8 encoded string
**
** @param      str   The string
**
** @return     Number of bytes required to store the UTF-8 string in memory
*/

size_t	ft_wcslen(const wchar_t *str)
{
	int		i;
	size_t	size;

	size = 0;
	i = 0;
	while (str && str[i])
		size += ft_wcharlen(str[i++]);
	return (size);
}
