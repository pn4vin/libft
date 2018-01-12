/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:14:27 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/05 14:18:25 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

/*
** @brief      Output the formatted string
**
** @param      format     The template string
** @param      ellipses   optional arguments
**
** @return     Formatted string
*/

char	*ft_sprintf(const char *format, ...)
{
	va_list	args;
	t_node	*content;
	char	*res;

	content = NULL;
	va_start(args, format);
	get_next_arg(NULL, args, format);
	va_end(args);
	res = process_format(format, &content);
	clean_lst(&content);
	return (res);
}
