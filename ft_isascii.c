/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:08:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 19:10:52 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      test argument for being within ASCII range [0, 127]
**
** @param      c     argument to be checked
**
** @note       There is no difference in what representation the number is
**             written, as the compiler will convert and store it in binary.
**             Read more here:
** @link https://www.cs.umd.edu/class/sum2003/cmsc311/Notes/BitOp/hexoctal.html
**
** @return     if c is contained by ASCII set, function returns 1 else
*/

int		ft_isascii(int c)
{
	return (c >= 0 && c <= 0177);
}
