/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:18:06 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/06/28 18:18:22 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

long long	ft_pow(int base, int exponent)
{
	long long	res;
	int			i;

	res = 1;
	i = 0;
	while (i++ < exponent)
		res *= base;
	return (res);
}
