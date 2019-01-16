/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 22:59:36 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/12/19 22:59:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

void	string_print(const char *format, char **start)
{
	if (!start)
		return ;
	while (*start)
		ft_printf(format, *start++);
}

void	nbr_print(const char *format, t_spec *spec, int *start)
{
	int		i;

	if (!start)
		return ;
	i = 0;
	while (i < spec->width)
		ft_printf(format, start[i++]);
}

/*
** Print array according to the format specified
**
** Be careful: format must be very strict "%c" for type of array elements
** Caution: %S will be ignored
*/

int		ft_arprintf(const char *format, ...)
{
	va_list	args;
	size_t	speclen;
	t_spec	*spec;

	va_start(args, format);
	MALLCHECK(spec = (t_spec *)malloc(sizeof(t_spec)));
	while (*format)
	{
		if (*format == '%')
		{
			CHECKSPECKLEN((speclen = parse_specifier(format)));
			init_spec(spec, format, speclen);
			if (spec->type == 's')
				string_print(format, va_arg(args, char **));
			else if (ft_strchr("dDiuUoOuUxXbB", spec->type))
				nbr_print(format, spec, va_arg(args, int *));
			return (1);
		}
		format++;
	}
	va_end(args);
	return (0);
}
