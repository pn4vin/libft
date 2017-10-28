/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:18:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 17:24:26 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Convert lowercase letter representation to upper-case letter if
**             one exists; otherwise argument is returned unchanged
**
** @param      c     unsigned char representation of character constant
**
** @return     corresponding upper-case version if one exists
*/

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
