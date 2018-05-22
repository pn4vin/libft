/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:17:30 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/10 11:22:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/*
** @brief      Push front to the list. Initialize list if head_ref point to NULL
**
** @param      head_ref  The head reference
** @param      node      The node
*/

void	ft_lstpush(t_list **head_ref, t_list *node)
{
	t_list	*tmp;

	if (!*head_ref)
		*head_ref = node;
	else
	{
		tmp = *head_ref;
		*head_ref = node;
		(*head_ref)->next = tmp;
	}
}
