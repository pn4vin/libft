/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 14:40:08 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/29 14:44:04 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      test character for white-space
**
**             White-space character set comprises:
**
**             ASCII  |  Name
**             
**             32     |  space
**             09     |  horizontal tab
**             10     |  line feed
**             11     |  vertical tab
**             12     |  form feed
**             13     |  carriage return
**
** @param      c     char to be checked
**
** @return     1 if character is either a space, horizontal tab
*/

int		ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}