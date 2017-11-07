/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:11:59 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 19:17:38 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Test char c to be alphabetic, either lower- or upper-case
**
** @param      c     char to be tested
**
** @note       Parentheses around AND statements are reduntant because it has
**             greater precedence over OR
**
** @return     1 if char is in range [A-Z] or [a-z]
*/

int		ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
