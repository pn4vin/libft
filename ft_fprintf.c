/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:14:12 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/05 14:16:58 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

/*
** @brief      Output the formatted string to file descriptor
**
** @param      fd         File descriptor
** @param      format     The template string
** @param      ellipses   optional arguments
**
** @return     Number of characters printed
*/

int		ft_fprintf(int fd, const char *format, ...)
{
	va_list	args;
	t_node	*content;
	char	*combined;
	int		len;

	content = NULL;
	va_start(args, format);
	get_next_arg(NULL, args, format);
	combined = process_format(format, &content);
	va_end(args);
	len = (int)content_size(content);
	write(fd, combined, len);
	clean_lst(&content);
	free(combined);
	return (len);
}
