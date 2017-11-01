/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:06:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/31 18:36:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Compare strings lexicographically
**
** @note       comparison is done using unsigned characters, so that '\200' is
**             greater than '\0'
**
** @param      s1    String 1
** @param      s2    String 2
**
** @return     Difference between the first non-equivalent pair, or zero if the
**             null-terminator reached, which would mean that strings are equal.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (*p1 == *p2 && !(*p1 == '\0' || *p2 == '\0'))
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}
