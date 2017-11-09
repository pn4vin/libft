/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:25:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/08 22:37:49 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Reverse list by switching pointers to opposite side
**
** @param      alst  The address of list to be reversed
**
** @return     { description_of_the_return_value }
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
