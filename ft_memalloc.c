/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:05:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/06 11:05:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Allocate memory and initialize it to 0
**
** @param[in]  size  The size
**
** @return     pointer to allocated memory area or NULL if malloc failed.
*/

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		mem[i++] = 0;
	return ((void *)mem);
}
