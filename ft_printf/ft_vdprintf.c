/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:14:12 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:20:29 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief      Output the formatted string to file descriptor
**
** @param      fd         File descriptor
** @param      format     The template string
** @param      ellipses   optional arguments
**
** @return     Number of characters printed
*/

int		ft_vdprintf(int fd, const char *format, va_list va_start)
{
	t_printf_node	*content;
	char			*combined;
	int				len;

	content = NULL;
	get_next_arg(NULL, va_start, format);
	combined = process_format(format, &content);
	va_end(va_start);
	len = (int)content_size(content);
	write(fd, combined, len);
	clean_lst(&content);
	free(combined);
	return (len);
}
