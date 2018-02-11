/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:58:08 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:27:16 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Convert wide character to multibyte sequence
**
** @param      c     utf-8 char
**
** @return     ASCII-converted char
*/

char	*ft_wcrtomb(int c)
{
	char	*chr;

	chr = ft_strnew((size_t)ft_wcharlen(c));
	if (c <= (1 << 7))
		chr[0] = (char)c;
	else if (c <= (1 << 11))
	{
		chr[0] = (char)(((c >> 6) & 0x1F) | 192);
		chr[1] = (char)(((c & 0x3F) | 0x80));
	}
	else if (c <= (1 << 16))
	{
		chr[0] = (char)(((c >> 12) & 0x0F) | 224);
		chr[1] = (char)(((c >> 6) & 0x3F) | 0x80);
		chr[2] = (char)(((c & 0x3F) | 0x80));
	}
	else
	{
		chr[0] = (char)(((c >> 18) & 7) | 240);
		chr[1] = (char)(((c >> 12) & 0x3F) | 0x80);
		chr[2] = (char)(((c >> 6) & 0x3F) | 0x80);
		chr[3] = (char)((c & 0x3F) | 0x80);
	}
	return (chr);
}
