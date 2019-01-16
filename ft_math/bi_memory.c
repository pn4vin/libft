/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:24:32 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 19:24:05 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_memory.h"

/*
** @brief Allocate big integer in memory
**
** @param size # of blocks
** @return t_bigint*
*/

t_bigint	*bi_alloc(size_t size)
{
	t_bigint	*bi;

	bi = (t_bigint *)malloc(sizeof(t_bigint));
	bi->sign = 0;
	bi->size = size;
	bi->arr = (int *)ft_memalloc(sizeof(int) * size);
	return (bi);
}

/*
** @brief Make a copy of big integer
**
** @param bi
** @return t_bigint*
*/

t_bigint	*bi_copy(t_bigint *bi)
{
	t_bigint	*cpy;
	size_t		i;

	cpy = bi_alloc(bi->size);
	cpy->sign = bi->sign;
	i = 0;
	while (i < bi->size)
	{
		cpy->arr[i] = bi->arr[i];
		i++;
	}
	return (cpy);
}

/*
** @brief Cut empty blocks in front of the number
**
** @param a
** @return t_bigint*
*/

t_bigint	*shrink_to_fit(t_bigint *a)
{
	size_t	n_zeros;
	int		*old;
	int		i;

	if (a->size == 1 && a->arr[0] == 0)
		return (a);
	n_zeros = 0;
	while (n_zeros < a->size)
	{
		if (a->arr[n_zeros] != 0)
			break ;
		n_zeros++;
	}
	if (n_zeros == 0)
		return (a);
	old = a->arr;
	a->arr = ft_memalloc(sizeof(int) * (a->size - n_zeros));
	i = -1;
	while (++i < (int)((int)a->size - n_zeros))
		a->arr[i] = old[i + n_zeros];
	a->size -= n_zeros;
	free(old);
	return (a);
}

/*
** @brief Release integer structure
**
** @param abi
*/

void		bi_release(t_bigint **abi)
{
	free((*abi)->arr);
	ft_memdel((void **)abi);
}

/*
** @brief Replace content of first integer <a> with the second one <b>
**
** @notes: content of <a> is lost forever, begone, not to be seen since.
** @param a
** @param b
*/

void		bi_replace(t_bigint *a, t_bigint *b)
{
	int		*old;

	a->sign = b->sign;
	a->size = b->size;
	old = a->arr;
	a->arr = b->arr;
	ft_memdel((void **)&old);
}
