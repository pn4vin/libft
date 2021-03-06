/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:25:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:23 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/*
** @brief      Reverse list by switching pointers to opposite side
**
** @param      alst  The address of list to be reversed
**
** @return     Pointer to the head of the reversed list
*/

t_list		*ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*next;

	if (!alst || !*alst)
		return (NULL);
	prev = NULL;
	while (*alst)
	{
		next = (*alst)->next;
		(*alst)->next = prev;
		prev = *alst;
		*alst = next;
	}
	return (prev);
}
