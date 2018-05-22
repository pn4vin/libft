/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:23:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:11 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/*
** @brief      Iterate through list, applying function f to each element
**
** @param      lst   The list
** @param      f     Function to be applied
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *))
{
	if (lst != NULL && f != NULL)
	{
		while (lst != NULL)
		{
			f(lst);
			lst = lst->next;
		}
	}
}
