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

#include "ft_tell.h"

/*
** @brief      Output <message> to <where> and stop program execution with
**             <exit_value> return value.
**
** @param      message  The message
*/

void	ft_panic(char *message, int where, int exit_value)
{
	ft_putendl_fd(message, where);
	exit(exit_value);
}
