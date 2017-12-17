/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:57:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/08 08:28:59 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Put list to standard output
**
** @note       Node's str is expected to be of type (char *)
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
