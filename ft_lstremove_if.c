/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 22:39:43 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/09 22:40:46 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Remove all elements of list for which the function returned TRUE.
**
** @param      ahead  The reference to the head
** @param      f      Function that takes the node's content and outputs boolean
*/

void	ft_lstremove_if(t_list **ahead, int (*f)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!ahead || !*ahead)
		return ;
	while (*ahead && f((*ahead)->content))
	{
		tmp = *ahead;
		*ahead = (*ahead)->next;
		free(tmp);
	}
	head = *ahead;
	while (head && head->next)
	{
		while (head->next && f(head->next->content))
		{
			tmp = head->next;
			head->next = tmp->next;
			free(tmp);
		}
		if (head->next)
			head = head->next;
	}
}
