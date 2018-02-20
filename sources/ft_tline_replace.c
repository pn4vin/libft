/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_line_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:44:27 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/19 16:00:57 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Replace dst t_line with src t_line, freeing <dst> resources
**
** @param      dst   The destination
** @param      src   The source
*/

void	ft_tline_replace(t_line *dst, t_line *src)
{
	ft_memdel((void **) &dst->str);
	dst->str = ft_memalloc(src->len);
	ft_memcpy(dst->str, src->str, src->len);
	dst->len = src->len;
}
