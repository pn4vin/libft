/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:50:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/04 14:50:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Copy strings
**
** @param      dst   The destination
** @param      src   The source
**
** @return     pointer to dst
*/

char	*ft_strcpy(char *dst, const char *src)
{
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}
