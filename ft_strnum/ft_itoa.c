/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:45:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/29 21:45:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strnum.h"

/*
** @brief      Convert integet to it's byte string representation.
**
** Equivalent to ft_itoa_base(n, 10)
**
** @param      n     The number to be converted
** @param      base  The base or radix
**
** @return     String storing the result of convertion
*/

char		*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
