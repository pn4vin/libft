/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 20:31:25 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:48:25 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief      Get the length of the decimal integer (number of digits)
**
** @param      integer  The integer
**
** @return     The length of the argument
*/

ssize_t	get_int_length(ssize_t integer)
{
	ssize_t i;

	i = 0;
	while ((integer /= 10))
		i++;
	return (i);
}

/*
** @brief      Determines if type field is a valid one.
**
** @param      c     type field
**
** @return     True if valid type, False otherwise.
*/

t_bool	is_valid_type(int c)
{
	return (t_bool)(ft_strchr("%%dDiuUpoOuUxXbBcCsSnkr", c));
}

size_t	nonprintable_size(char *s, t_bool cnt)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s >= 32 && *s <= 126)
			size++;
		else
			size += cnt ? 1 : 3;
		s++;
	}
	return (size);
}

char	*map_nonprint(int c)
{
	static char	*lookup[32] = {"NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK",
	"\\a", "\\b", "\\t", "\\n", "\\v", "\\f", "\\r", "SO", "SI", "DLE", "DC1",
	"DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS",
								"GS", "RS", "US"};

	return (c < 32 ? lookup[c] : "DEL");
}

char	*get_nonprintables(t_spec *spec, char *s)
{
	char	*res;
	char	*non_print;
	int		i;

	(void)spec;
	res = ft_strnew(nonprintable_size(s, FALSE));
	i = 0;
	while (*s)
	{
		if (*s >= 32 && *s <= 126)
			res[i++] = *s;
		else
		{
			non_print = map_nonprint(*s);
			while (*non_print)
				res[i++] = *non_print++;
		}
		s++;
	}
	return (res);
}
