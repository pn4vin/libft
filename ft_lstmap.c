/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:24:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/07 18:26:56 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Create a new list where each element is the result of function f
**             call
**
** @param      lst   The list
** @param      f     Function to generate new element
**
** @return     Brand new list
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;

	new_lst = NULL;
	if (lst != NULL && f != NULL)
	{
		while (lst)
		{
			ft_lstappend(&new_lst, f(lst));
			lst = lst->next;
		}
	}
	return (new_lst);
}
