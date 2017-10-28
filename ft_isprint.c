/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:33:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 18:13:46 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Test whether an argument is a printable character
**
** @param      c     unsigned char value to be checked
**
** @note       argument is of type int to be capable of holding EOF value, which
**             must be outside of the unsigned char region (x < 0 || x > 255)
**
** @return     1 if c is printable else 0
*/

int		ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
