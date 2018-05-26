/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:45:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/29 20:45:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Convert character to it's integer (base 10) representation, given
**             arbitrary base.
**
** @param      c     character to be converted
** @param      base  ordered radix string of unique values
**
** @return     digit representation in a given base. If no such symbol found in
**             base, return -1.
*/

int		ft_ctoi_base(char c, const char *base)
{
	int i;

	i = 0;
	while (base && base[i])
		if (c == base[i++])
			return (--i);
	return (-1);
}
