/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:20:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 15:20:10 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      convert an upper-case letter to the corresponding lower-case
**             letter
**
** @param      c     unsigned char value or EOF
**
** @return     if the argument is upper-case, returns the corresponding
**             lower-case letter; otherwise, the argument is returned unchanged
*/

int		ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
