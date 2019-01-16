/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 23:08:20 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/15 23:08:52 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_memory.h"

char	*ft_strappend(char *s, char c)
{
	char	*r;
	size_t	len;

	len = ft_slen(s);
	r = ft_strnew(len + 1);
	ft_memcpy(r, s, len);
	r[len] = c;
	free(s);
	return (r);
}
