/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 13:44:37 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/04 20:40:52 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

/*
** @brief      Map the type provided to the proper va_arg
**
** @param      type  The type
** @param      len   The length field
** @param      arg   The argument list
**
** @return     Properly converted va_arg
*/

static void	*map_type(t_spec *spec, va_list arg)
{
	if (ft_strchr("XxOoBbUup", spec->type))
		return (fetch_nbr(spec->length, spec->type, arg, FALSE));
	else if (ft_strchr("idD", spec->type))
		return (fetch_nbr(spec->length, spec->type, arg, TRUE));
	else if (ft_strchr("rsS", spec->type))
		return (spec->type == 'S' || spec->length == l ? va_arg(arg, wchar_t *)
										: va_arg(arg, int *));
	else if (ft_strchr("cC", spec->type))
		return ((int *)(uintptr_t)(spec->type == 'C' || spec->length == l ?
				va_arg(arg, wchar_t) : (unsigned char)va_arg(arg, int)));
	else if (spec->type == 'n')
		return (va_arg(arg, int *));
	else
		return (NULL);
}

/*
** @brief      Gets the next argument from the argument list
**
** @param      pos     The position (index or zero if not specified)
** @param      init    Initialize static list if specified
** @param      format  Format string (or "*" to specify width/prec)
**
** @return     The next argument as a pointer to void
*/

void		*get_next_arg(t_spec *spec, va_list init, const char *format)
{
	static va_list	args;
	static va_list	non_pos_args;
	va_list			tmp_list;
	void			*ret;
	int				i;

	init ? va_copy(non_pos_args, init) : 0;
	init ? va_copy(args, init) : 0;
	if (init)
		return (NULL);
	if (format && *format == '*')
		return ((void *)(uintptr_t)va_arg(non_pos_args, int));
	if (!spec->pos)
		ret = map_type(spec, non_pos_args);
	else
	{
		va_copy(tmp_list, args);
		i = 0;
		while (i++ < spec->pos - 1)
			va_arg(tmp_list, void *);
		ret = map_type(spec, tmp_list);
		va_end(tmp_list);
	}
	return (ret);
}
