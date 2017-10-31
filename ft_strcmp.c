/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:06:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/31 18:30:56 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Compare strings lexicographically
**
** @param      s1    String 1
** @param      s2    String 2
**
** @return     Difference between the first non-equivalent pair, or zero if the
**             null-terminator reached, which would mean that strings are equal.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char		c1;
	unsigned char		c2;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	c1 = *p1++;
	c2 = *p2++;
	while (c1 == c2 && !(c1 == '\0' || c2 == '\0'))
	{
		c1 = *p1++;
		c2 = *p2++;
	}
	return (c1 - c2);
}
