/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:19:24 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:21:56 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** @brief      Initialize specifier structure
**
** @param      format   The format
** @param      speclen  The speclen
**
** @return     Initializes specifier
*/

t_spec		*init_spec(const char *format, size_t speclen)
{
	t_spec *spec;

	MALLCHECK(spec = (t_spec *)malloc(sizeof(t_spec)));
	spec->spec = ft_strdup(format);
	spec->length = parse_length(format, speclen);
	spec->flags = parse_flags(format, speclen);
	spec->pos = parse_pos(format, speclen);
	spec->width = parse_width(spec, format, speclen);
	spec->prec = parse_prec(spec, format, speclen);
	spec->type = spec->spec[speclen - 1];
	if (spec->type == 'x' || spec->type == 'X' || spec->type == 'p')
		spec->base = 16;
	else if (spec->type == 'o' || spec->type == 'O')
		spec->base = 8;
	else if (spec->type == 'b' || spec->type == 'B')
		spec->base = 2;
	else
		spec->base = 10;
	return (spec);
}

/*
** @brief      Map a specifier type to the appropriate function
**
** @param      specifier  The specifier
** @param      len        The length
**
** @return     The function if valid type was provided, otherwise NULL
*/

t_specptr	map_function(const char *specifier, ssize_t len)
{
	if (specifier[len - 1] == '%')
		return (put_percent);
	else if (ft_strchr("dDi", specifier[len - 1]))
		return (put_integer);
	else if (specifier[len - 1] == 'c' || specifier[len - 1] == 'C')
		return (put_char);
	else if (specifier[len - 1] == 's' || specifier[len - 1] == 'S')
		return (put_string);
	else if (specifier[len - 1] == 'p')
		return (put_address);
	else if (ft_strchr("oOuUxXbB", specifier[len - 1]))
		return (put_uxob);
	else if (specifier[len - 1] == 'n')
		return (put_written_chars);
	else if (specifier[len - 1] == 'r')
		return (put_nonprintable);
	else if (specifier[len - 1] == 'k')
		return (put_date);
	else
		return (put_generic);
}

/*
** @brief      Parse specifier and return it's length
**
** @param      format  The format
**
** @return     Length of the specifier
*/

size_t		parse_specifier(const char *format)
{
	const char	*start;

	start = format++;
	while (*format)
	{
		if ((is_valid_type(*format)) ||
				!ft_strchr("0123456789#+-. *$lLthzj,:;_", *format))
			return (format - start + 1);
		format++;
	}
	return (0);
}

/*
** @brief      Process format string
**
** @param      format   The format
** @param      content  The content ArrayList
**
** @return     String with all conversions applied (neat-o)
*/

char		*process_format(const char *format, t_node **content)
{
	t_specptr	f;
	size_t		speclen;
	t_spec		*spec;
	int			non_conv;

	non_conv = 0;
	while (*format)
	{
		if (*format == '%')
		{
			CHECKSPECKLEN((speclen = parse_specifier(format)));
			f = map_function(format, speclen);
			spec = init_spec(format, speclen);
			f(content, spec);
			format += speclen;
			free(spec->spec);
			free(spec);
		}
		while (format && *format && *format != '%' && ++non_conv)
			format++;
		non_conv ? expand_n(content, format - non_conv, non_conv) : 0;
		non_conv ? non_conv = 0 : 0;
	}
	return (collect_content(*content));
}

/*
** @brief      Formatted output conversion
**
** @param      format     Format string
** @param      ellipsis   Arguments corresponding to each format specifier
**
** @return     Number of characters printed
*/

int			ft_printf(const char *format, ...)
{
	va_list	args;
	t_node	*content;
	char	*combined;
	int		len;

	content = NULL;
	va_start(args, format);
	get_next_arg(NULL, args, format);
	combined = process_format(format, &content);
	va_end(args);
	len = (int)content_size(content);
	write(1, combined, len);
	clean_lst(&content);
	free(combined);
	return (len);
}
