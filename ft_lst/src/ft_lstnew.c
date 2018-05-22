/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:44:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:18 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_memory.h"

/*
** @brief      Initialize a new element of a linked list
**
** @param      content       The content
** @param      content_size  The content size
**
** @return     pointer to a new element. If memory allocation fails, return NULL
*/

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		if (content != NULL)
		{
			if ((new->content = malloc(content_size)) == NULL)
			{
				free(new);
				return (NULL);
			}
			ft_memcpy(new->content, content, content_size);
		}
		else
			new->content = NULL;
		new->content_size = content != NULL ? content_size : 0;
		new->next = NULL;
	}
	return (new);
}
