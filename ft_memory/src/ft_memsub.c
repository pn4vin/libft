/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:36:21 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/16 18:38:42 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_str.h"

/*
** @brief      Create a substring, operating directly on bytes
**
** @note       if start or len are not valid, the behavior is undefined.
**
** @param      s      Source string
** @param      start  Starting index of a new substring
** @param      len    The length
**
** @return     New, independent substring if everything OK, NULL if KO
*/

void	*ft_memsub(void *s, size_t start, size_t len, t_bool and_free)
{
	char	*res;

	res = ft_strnew(len);
	if (res != NULL && s != NULL)
	{
		ft_memcpy(res, s + start, len);
		if (and_free)
			ft_memdel(&s);
		return (res);
	}
	else
		return (NULL);
}
