/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 09:21:07 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/04 20:35:12 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

/*
** @brief      Parse the Flags field
**
** @note       the flags field can be zero or more (in any order) of:
**
**       -     left-align the output of this placeholder
**       +     prepend a plus for positive signed-numeric types
**      ` `    prepend a space for positive signed-numberic types. ignored if
**             '+' flag exists
**       0     if 'width' option is specified, prepend zeros for numeric types.
**             Detected by the fact that it cannot be preceded by number
**
**       #     [gG]      trailing zeros are not removed
**             [fFeEgG]  output always contains a decimal point
**             [oOxX]    0, 0x, 0X prepended to non-zero numbers
**
** @param      spec  The specifier
** @param      len   The length
**
** @return     flags
*/

t_flags		parse_flags(const char *spec, size_t len)
{
	t_flags	flags;
	size_t	i;

	flags = none;
	i = len >= 2 ? len - 2 : 0;
	while (i > 0)
	{
		if (spec[i] == '0' && !ft_isdigit(spec[i - 1]) && !(flags & zero) && \
											spec[i - 1] != '.')
			flags |= zero;
		else if (spec[i] == '-' && !(flags & minus))
			flags |= minus;
		else if (spec[i] == '+' && !(flags & plus))
			flags |= plus;
		else if (spec[i] == ' ' && !(flags & space))
			flags |= space;
		else if (spec[i] == '#' && !(flags & hash))
			flags |= hash;
		i--;
	}
	return (flags);
}

/*
** @brief      Parse optional position field (n$)
**
** @param      format   The format
** @param      speclen  The speclen
**
** @return     Index number if position is specified, otherwise 0
*/

int			parse_pos(const char *format, int speclen)
{
	int		i;
	int		pos;

	i = 1;
	pos = 0;
	while (i < speclen - 1)
	{
		if (format[i] == '$')
		{
			i--;
			while (i > 1 && ft_isdigit(format[i - 1]))
				i--;
			return (ft_atoi(&(format[i])));
		}
		i++;
	}
	return (pos);
}

/*
** @brief      Parse the <width> field, which specifies the length of the
**             expanded specifier. If <width> > len(string), padding is added.
**
** @note       <width> can be specified several times. The last one has the
**             highest priority.
**
** @param      spec  The specifier
** @param      str   The string
** @param      len   The length
**
** @return     the width
*/

int			parse_width(t_spec *spec, const char *str, size_t len)
{
	size_t	i;
	int		width;

	i = 1;
	width = 0;
	while (i < len - 1)
	{
		if (str[i] == '.' && i++)
			while (str[i] && ft_isdigit(str[i]))
				i++;
		if (ft_isdigit(str[i]) && str[i] != '0' &&
			str[i - 1] != '.' && str[i + 1] != '$')
		{
			width = ft_atoi(&(str[i]));
			i += get_int_length(width);
		}
		else if (str[i - 1] != '.' && str[i] == '*')
			width = (int)get_next_arg(spec, NULL, "*");
		i++;
	}
	width < 0 ? spec->flags |= minus : 0;
	return (width < 0 ? -width : width);
}

/*
** @brief      Parse length specifier
**
** @param      spec  The len
** @param      len   The length
** @param      arg   The argument
**
** @return     Pointer to the argument, casted to the proper type
*/

t_length	parse_length(const char *spec, ssize_t len)
{
	t_length	length;
	char		*ndl;

	length = l_none;
	if (ft_memchr(spec, 'l', len) && l > length)
		length = l;
	if ((ndl = ft_strnstr(spec, "ll", len)) && !ndl && ll > length)
		length = ll;
	if (ft_memchr(spec, 'z', len) && z > length)
		length = z;
	if (ft_memchr(spec, 'j', len) && j > length)
		length = j;
	if (ft_memchr(spec, 't', len) && t > length)
		length = t;
	if ((ndl = ft_strnstr(spec, "hh", len)) && hh > length)
		length = hh;
	if (ft_memchr(spec, 'h', len) && !ndl && h > length)
		length = h;
	return (length);
}

/*
** @brief      Parse the precision field
**
** @param      spec  The specifier
** @param      len   The length
**
** @return     -1 if the field was omitted, otherwise precision
*/

int			parse_prec(t_spec *spec, const char *format, ssize_t len)
{
	int		i;
	int		prec;

	i = 1;
	prec = -1;
	while (i < len - 1)
	{
		if (format[i] == '.')
		{
			prec = ft_isdigit(format[i + 1]) ? ft_atoi(&(format[i + 1])) : 0;
			i += get_int_length(prec);
		}
		if (format[i] == '.' && format[i + 1] == '*')
			prec = (int)get_next_arg(spec, NULL, "*");
		i++;
	}
	return (prec < 0 ? -1 : prec);
}
