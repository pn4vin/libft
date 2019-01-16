/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:38:43 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:21:44 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_str.h"
#include "ft_strnum.h"

/*
** @brief Create integer from unsigned primitive type
**
** @param v
** @return t_bigint*
*/

t_bigint	*bi_utobi(unsigned long long v)
{
	t_bigint	*bi;
	size_t		i;

	bi = bi_alloc(bi_usize(v));
	i = bi->size - 1;
	while (v > 0)
	{
		bi->arr[i--] = (int)(v % SPLIT_CONST);
		v /= SPLIT_CONST;
	}
	return (bi);
}

/*
** @brief Create integer from signed primitive type
**
** @param v
** @return t_bigint*
*/

t_bigint	*bi_itobi(long long v)
{
	t_bigint	*bi;
	size_t		i;

	bi = bi_alloc(bi_isize(v));
	bi->sign = v < 0;
	i = bi->size - 1;
	while (v != 0)
	{
		bi->arr[i--] = ft_abs((int)(v % SPLIT_CONST));
		v /= SPLIT_CONST;
	}
	return (bi);
}

/*
** @brief Create big integer from string
**
** @note: assuming valid formatting
** @param v
** @return t_bigint*
*/

t_bigint	*bi_stobi(char *v)
{
	t_bigint	*bi;
	t_bigint	*tmp;
	size_t		i;
	size_t		k;

	if (!v || ft_slen(v) == 0)
		return (bi_zero());
	bi = bi_zero();
	i = ft_slen(v);
	k = 0;
	if (v[k] == '-')
	{
		bi->sign = 1;
		k++;
	}
	while (k < i)
	{
		bi_ishift10(bi, 1);
		bi_iadd(bi, (tmp = bi_itobi(v[k] - '0')));
		bi_release(&tmp);
		if (i == 0)
			break ;
		k++;
	}
	return (bi);
}
