/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 11:28:38 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/06/14 11:29:20 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief      Print to STDOUT, accepting va_list argument instead of ellipsis
**
**             The reason behind is to be able to use ft_printf inside the
**             enclosure function.
**
** @param      format     The template string
** @param      va_list    Pointer to the start of variable argument list
**
** @return     Formatted string
*/

int		ft_vprintf(const char *format, va_list va_start)
{
	t_node	*content;
	char	*combined;
	int		len;

	content = NULL;
	get_next_arg(NULL, va_start, format);
	combined = process_format(format, &content);
	va_end(va_start);
	len = (int)content_size(content);
	write(1, combined, len);
	clean_lst(&content);
	free(combined);
	return (len);
}
