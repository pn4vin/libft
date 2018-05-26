/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:17:46 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 19:24:28 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Test character for being a digit
**
** @param      c     char to check
**
** @return     1 if char in range [0-9], else 0
*/

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
