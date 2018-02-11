/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:33:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:26:02 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Create a substring
**
** @note       if start or len are not valid, the behavior is undefined.
**
** @param      s      Source string
** @param      start  Starting index of a new substring
** @param      len    The length
**
** @return     New, independent substring if everything OK, NULL if KO
*/

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*res;

	res = ft_strnew(len);
	if (res != NULL && s != NULL)
		return (ft_strncpy(res, s + start, len));
	else
		return (NULL);
}
