/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:06:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 20:59:17 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Test character for being alphabetic or digit
**
** @include libft.h
**
** @param      c     char to be checked
**
** @return     1 if ft_isalpha(c) == 1 or ft_isdigit(c) == 1; otherwise, 0
*/

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
