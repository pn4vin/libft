/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_and_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:24:11 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/21 13:25:22 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_tell.h"

/*
** @brief      Output <message> to STDERR and stop program execution with
**             <exit_value> return value.
**
** @param      message  The message
*/

void	ft_panic(int exit_value, char *format, ...)
{
	va_list	va;

	va_start(va, format);
	ft_vdprintf(2, format, va);
	exit(exit_value);
}
