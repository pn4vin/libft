/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:31:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:56 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/*
** @brief      Append new element to the end of the list
**
** @param      alst       Address of the list
** @param      new        New element to be added
*/

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	if (!lst)
		*alst = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}
