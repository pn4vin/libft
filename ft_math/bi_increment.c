/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_increment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 22:25:01 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/16 22:26:36 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Increment big integer by one
**
** @param bi
** @return t_bigint*
*/

t_bigint	*bi_increment(t_bigint *bi)
{
	t_bigint	*tmp;

	tmp = bi_one();
	bi_iadd(bi, tmp);
	bi_release(&tmp);
	return (bi);
}
