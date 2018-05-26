/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 14:32:35 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:23:07 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

/*
** @brief      Process %[sS] placeholder
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_string(t_node **content, t_spec *spec)
{
	size_t	len;
	char	*s;

	if (spec->type == 'S' || spec->length == l)
		s = ft_wcstombs(get_next_arg(spec, NULL, NULL), spec->prec);
	else
		s = get_next_arg(spec, NULL, NULL);
	if (!s)
		expand_n(content, "(null)", spec->prec > -1 ? spec->prec : 6);
	if (spec->prec >= 0 && spec->prec < (int)ft_slen(s))
		len = !s ? 6 : (size_t)spec->prec;
	else
		len = !s && spec->prec == -1 ? 6 : ft_slen(s);
	if (spec->flags & minus)
	{
		expand_n(content, s, len);
		add_pad(content, spec, len);
	}
	else
	{
		add_pad(content, spec, len);
		expand_n(content, s, len);
	}
	if (spec->type == 'S' || spec->length == l)
		free(s);
}

/*
** @brief      Process %[cC] placeholder
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_char(t_node **content, t_spec *spec)
{
	char	*expanded;
	int		c;
	size_t	explen;
	t_bool	is_utf8;

	is_utf8 = (t_bool)(spec->type == 'C' || spec->length == l);
	c = (int)get_next_arg(spec, NULL, NULL);
	if (is_utf8 && MB_CUR_MAX == 4)
		expanded = ft_wcrtomb(c);
	else
	{
		expanded = ft_strnew(1);
		expanded[0] = (unsigned char)c;
	}
	explen = (size_t)(is_utf8 && MB_CUR_MAX == 4 ? ft_wcharlen(c) : 1);
	spec->flags & minus ? expand_n(content, expanded, explen) :
							add_pad(content, spec, explen);
	spec->flags & minus ? add_pad(content, spec, explen) :
							expand_n(content, expanded, explen);
	free(expanded);
}

/*
** @brief      Default routine for unrecognized specifier
**
** @param      content  The content
** @param      spec     The specifier
**
** @return     1 (as a number of successfully written symbols)
*/

void	put_generic(t_node **content, t_spec *spec)
{
	char	*expanded;

	expanded = ft_strnew(1);
	expanded[0] = spec->type;
	if (spec->flags & minus)
	{
		expand_n(content, expanded, ft_slen(expanded));
		add_pad(content, spec, ft_slen(expanded));
	}
	else
	{
		add_pad(content, spec, ft_slen(expanded));
		expand_n(content, expanded, ft_slen(expanded));
	}
	free(expanded);
}

/*
** @brief      Put a string with non-printable characters
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_nonprintable(t_node **content, t_spec *spec)
{
	char	*expand;
	size_t	len;
	char	*s;

	s = get_next_arg(spec, NULL, NULL);
	expand = get_nonprintables(spec, s);
	if (!s)
		expand_n(content, "(null)", spec->prec > -1 ? spec->prec : 6);
	if (spec->prec >= 0 && spec->prec < (int)ft_slen(expand))
		len = !s ? 6 : (size_t)spec->prec;
	else
		len = !s && spec->prec == -1 ? 6 : ft_slen(expand);
	if (spec->flags & minus)
	{
		expand_n(content, expand, len);
		add_pad(content, spec, len);
	}
	else
	{
		add_pad(content, spec, len);
		expand_n(content, expand, len);
	}
	free(expand);
}

/*
** @brief      Put a date in ISO 8601 format.
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_date(t_node **content, t_spec *spec)
{
	time_t	tm;
	t_nbr	nbr;
	char	*expand;

	spec->prec = 2;
	tm = time(NULL);
	nbr.u = 1970UL + tm / 86400UL / 365UL;
	expand = itoa_deluxe(nbr, spec, 10, FALSE);
	expand_n(content, expand, ft_slen(expand));
	expand_n(content, "-", 1);
	free(expand);
	nbr.u = (tm / 86400UL * 31UL) % 12UL + 1UL;
	expand = itoa_deluxe(nbr, spec, 10, FALSE);
	expand_n(content, expand, ft_slen(expand));
	expand_n(content, "-", 1);
	free(expand);
	nbr.u = (tm / 86400UL) % 30 - 12 + 1;
	expand = itoa_deluxe(nbr, spec, 10, FALSE);
	expand_n(content, expand, ft_slen(expand));
	free(expand);
}
