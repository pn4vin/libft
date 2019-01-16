/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:57:50 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/13 20:58:13 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

/*
** @brief Add zero-ed blocks to the beginning of integer
**
** bi_prepend_blocks(5, 3) will thus give 000 000 000 005
** @param bi
** @param n
*/

void	bi_prepend_blocks(t_bigint *bi, size_t n)
{
	int			*old;
	size_t		i;

	old = bi->arr;
	bi->arr = (int *)malloc(sizeof(int) * (bi->size + n));
	i = bi->size + n;
	while (i > n)
	{
		bi->arr[i - 1] = old[i - n - 1];
		i--;
	}
	while (i > 0)
	{
		bi->arr[i - 1] = 0;
		i--;
	}
	bi->size += n;
	free(old);
}

/*
** @brief Append zero-ed blocks to the end of big integer
**
** bi_append_blocks(5, 3) will thus give 005 000 000 000
** @param bi big integer
** @param n # of blocks
*/

void	bi_append_blocks(t_bigint *bi, size_t n)
{
	int			*old;
	size_t		i;

	old = bi->arr;
	bi->arr = (int *)malloc(sizeof(int) * (bi->size + n));
	i = 0;
	while (i < bi->size)
	{
		bi->arr[i] = old[i];
		i++;
	}
	while (i < bi->size + n)
	{
		bi->arr[i] = 0;
		i++;
	}
	bi->size += n;
	free(old);
}

/*
** @brief Cut last <n> blocks from the number
**
** @param bi
** @param n
*/

void	bi_end_cut(t_bigint *bi, size_t n)
{
	int		*old;
	size_t	i;

	if (n > bi->size)
		return ;
	else if (n == bi->size)
	{
		bi->size = 1;
		free(bi->arr);
		bi->arr = malloc(sizeof(int) * 1);
		bi->arr[0] = 0;
		return ;
	}
	old = bi->arr;
	bi->arr = (int *)malloc(sizeof(int) * (bi->size - n));
	i = 0;
	while (i < bi->size - n)
	{
		bi->arr[i] = old[i];
		i++;
	}
	bi->size -= n;
	free(old);
}
