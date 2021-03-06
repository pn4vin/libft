/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:43:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:53 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

/*
** @brief      Add the element new to the beginning of the list
**
** @param      alst       Address of a pointer to the beginning of the list
** @param      new        New element
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list *head;

	if (alst != NULL && new != NULL)
	{
		head = *alst;
		*alst = new;
		new->next = head;
	}
}
