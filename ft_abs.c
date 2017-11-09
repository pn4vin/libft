/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:39:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/30 16:39:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Convert integer to it's absolute value
**
** @note       No check is performed, thus ft_abs(INT_MIN) will overflow. Be
**             heedful.
**
** @param      n     Integer
**
** @return     The absolute value of an argument
*/

int		ft_abs(int n)
{
	return (n < 0 ? -n : n);
}
