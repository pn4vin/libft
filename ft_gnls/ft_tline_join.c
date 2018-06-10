/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tline_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 12:13:21 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/20 12:16:32 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_gnls.h"

/*
** @brief      Join two lines, appending right to the left and freeing resources
**             of the <right> argument
**
** @param      left   The left t_line
** @param      right  The right t_line
*/

void	ft_tline_join(t_line *left, t_line *right)
{
	left->str = ft_realloc(left->str, left->len, left->len + right->len, TRUE);
	ft_memcpy(left->str + left->len, right->str, right->len);
	left->len = left->len + right->len;
}
