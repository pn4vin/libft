/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:47:23 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:22:41 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

/*
** @brief      Fetches a number, properly.
**
** @param      length  The length
** @param      type    The type
** @param      arg     The argument list
** @param      is_int  Indicates if the number should be integer
**
** @return     t_nbr union
*/

t_nbr	*fetch_nbr(t_length length, char type, va_list arg, t_bool is_int)
{
	static t_nbr nbr;

	if ((nbr.u = 0) || length == l || ft_strchr("DOUBp", type))
		is_int ? (unsigned long long int)(nbr.i = va_arg(arg, long int))
			: (nbr.u = va_arg(arg, unsigned long int));
	else if (length == ll)
		is_int ? (unsigned long long int)(nbr.i = va_arg(arg, long long))
			: (nbr.u = va_arg(arg, unsigned long long));
	else if (length == z)
		nbr.u = va_arg(arg, size_t);
	else if (length == j)
		nbr.i = va_arg(arg, intmax_t);
	else if (length == t)
		is_int ? (unsigned long long int)(nbr.i = va_arg(arg, ptrdiff_t))
			: (nbr.u = va_arg(arg, ptrdiff_t));
	else if (length == hh)
		is_int ? (unsigned long long int)(nbr.i = (char)va_arg(arg, int))
			: (nbr.u = (unsigned char)va_arg(arg, int));
	else if (length == h)
		is_int ? (unsigned long long int)(nbr.i = (short int)va_arg(arg, int))
			: (nbr.u = (unsigned short int)va_arg(arg, int));
	else
		is_int ? (unsigned long long int)(nbr.i = va_arg(arg, int))
			: (nbr.u = va_arg(arg, unsigned int));
	return (&nbr);
}

/*
** @brief      Adds a sign.
**
** @param      nbr   The number
** @param      spec  The specifier
**
** @return     Sign string if present, otherwise NULL
*/

char	*add_sign(t_nbr nbr, t_spec *spec)
{
	if (nbr.i < 0)
		return ("-");
	else if (!(spec->flags & plus) && spec->flags & space && nbr.i >= 0)
		return (" ");
	else if ((spec->flags & plus) && nbr.i >= 0)
		return ("+");
	else
		return (NULL);
}

char	*with_apostrophe(char *nbr, t_spec *spec)
{
	int		f;
	char	*tmp;
	int		i;
	int		j;

	if (!(spec->flags & apstr) || ft_slen(localeconv()->mon_thousands_sep) == 0)
		return (nbr);
	if (!(f = (int)(ft_slen(nbr) / 3 - (ft_slen(nbr) % 3 == 0))))
		return (nbr);
	tmp = ft_strnew(ft_slen(nbr) + f);
	i = (int)(ft_slen(nbr) - 1);
	while (f >= 0)
	{
		j = 0;
		while (j++ < 3 && i >= 0)
		{
			tmp[i + f] = nbr[i];
			i--;
		}
		if ((i + f) >= 0)
			tmp[i + f] = localeconv()->mon_thousands_sep[0];
		f--;
	}
	ft_strdel(&nbr);
	return (tmp);
}

/*
** @brief      Process %[idD] placeholder
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_integer(t_node **content, t_spec *spec)
{
	char	*expanded;
	char	*sign;
	t_nbr	nbr;

	nbr = *(t_nbr *)get_next_arg(spec, NULL, NULL);
	expanded = with_apostrophe(itoa_deluxe(nbr, spec, 10, True), spec);
	spec->flags &= spec->prec >= 0 ? ~zero : ~none;
	sign = add_sign(nbr, spec);
	if (spec->flags & minus)
	{
		expand_n(content, sign, 1);
		expand_n(content, expanded, ft_slen(expanded));
		add_pad(content, spec, ft_slen(expanded) + ft_slen(sign));
	}
	else
	{
		if (spec->flags & zero && ft_slen(sign))
			expand_n(content, sign, 1);
		add_pad(content, spec, ft_slen(expanded) + ft_slen(sign));
		if (!(spec->flags & zero) && ft_slen(sign))
			expand_n(content, sign, 1);
		expand_n(content, expanded, ft_slen(expanded));
	}
	free(expanded);
}

/*
** @brief      Process %[xXuUoObB] placeholder
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_uxob(t_node **content, t_spec *spec)
{
	t_nbr			nbr;
	char			*expanded;
	char			*prefix;

	nbr = *(t_nbr *)get_next_arg(spec, NULL, NULL);
	expanded = itoa_deluxe(nbr, spec, spec->base, False);
	spec->flags &= spec->prec >= 0 ? ~zero : ~none;
	prefix = get_prefix(spec, expanded, nbr);
	if (spec->flags & minus)
	{
		expand_n(content, prefix, ft_slen(prefix));
		expand_n(content, expanded, ft_slen(expanded));
		add_pad(content, spec, ft_slen(expanded) + ft_slen(prefix));
	}
	else
	{
		spec->flags & zero ? expand_n(content, prefix, ft_slen(prefix)) : 0;
		add_pad(content, spec, ft_slen(expanded) + ft_slen(prefix));
		!(spec->flags & zero) ? expand_n(content, prefix, ft_slen(prefix)) : 0;
		expand_n(content, expanded, ft_slen(expanded));
	}
	free(prefix);
	free(expanded);
}
