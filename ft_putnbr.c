/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:44:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/11/07 15:46:43 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Output number to stdout
**
** @param      n     Integer to be printed using stdout
*/

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
