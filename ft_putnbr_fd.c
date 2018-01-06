/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 13:31:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/07 13:33:47 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

/*
** @brief      Output the integer n to the provided file descriptor
**
** @param      n     Number
** @param      fd    File Descriptor
*/

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
	}
	ft_putchar_fd((char)(ft_abs(n % 10) + 48), fd);
}
