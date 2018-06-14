/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:14:27 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:24:04 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief      Output the formatted string, accepting arguments in va_list form
**             instead of ellipsis
**
** @param      format     The template string
** @param      ellipses   optional arguments
**
** @return     Formatted string
*/

char	*ft_vsprintf(const char *format, va_list va_start)
{
	t_node	*content;
	char	*res;

	content = NULL;
	get_next_arg(NULL, va_start, format);
	va_end(va_start);
	res = process_format(format, &content);
	clean_lst(&content);
	return (res);
}
