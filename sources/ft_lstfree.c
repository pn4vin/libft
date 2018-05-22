/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:47:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/08 22:53:21 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_memory.h"

/*
** @brief      free space of content
**
** @note       Default del( ) function for ft_lstdel and ft_lstdelone
** @param      content       The content
** @param      content_size  The content size
*/

void	ft_lstfree(void **acontent, size_t content_size)
{
	(void)content_size;
	ft_memdel(acontent);
}
