/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:31:21 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/02 18:33:58 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Check if the character provided is uppercase ASCII character
**
** @param      c     Character to check
**
** @return     1 if character in [A-Z], otherwise 0
*/

int		ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}
