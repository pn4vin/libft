/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:24:13 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:24:16 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Exponentiation of big integer using repeating multiplication
**
** @param a base
** @param n exponent
** @return t_bigint*
*/

t_bigint	*bi_pow(t_bigint *a, int n)
{
	t_bigint	*r;
	int			i;

	if (n < 0)
		return (bi_zero());
	r = bi_one();
	if (n == 0)
		return (r);
	i = 0;
	while (i < n)
	{
		bi_imul(r, a);
		i++;
	}
	return (r);
}
