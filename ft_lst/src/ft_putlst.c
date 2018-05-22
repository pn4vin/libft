/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:57:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:23:41 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "libft.h"

/*
** @brief      Put list to standard output
**
** @note       Node's content is expected to be of type (char *)
**
** @param      lst   List to be printed
*/

void	ft_putlst(t_list *lst)
{
	while (lst != NULL)
	{
		ft_putstr((char *)lst->content);
		ft_putstr(" -> ");
		lst = lst->next;
	}
	ft_putstr("NULL\n");
}
