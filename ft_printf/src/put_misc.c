/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_misc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 20:26:34 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/03/11 13:51:57 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

/*
** @brief      Process %% specifier
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_percent(t_node **content, t_spec *spec)
{
	size_t	explen;
	char	*expanded;

	expanded = ft_strdup("%");
	explen = ft_slen(expanded);
	if (spec->flags & minus)
	{
		expand_n(content, expanded, explen);
		add_pad(content, spec, explen);
	}
	else
	{
		add_pad(content, spec, explen);
		expand_n(content, expanded, explen);
	}
	free(expanded);
}

/*
** @brief      Process %p specifier
**
** @param      content  The content
** @param      spec     The specifier
*/

void	put_address(t_node **content, t_spec *spec)
{
	char			*expanded;
	char			*prefix;
	size_t			explen;
	t_nbr			nbr;

	nbr = *(t_nbr *)get_next_arg(spec, NULL, NULL);
	expanded = itoa_deluxe(nbr, spec, 16, FALSE);
	prefix = get_prefix(spec, expanded, nbr);
	explen = spec->prec >= 0 && nbr.u == 0 ?
			(size_t) spec->prec : ft_slen(expanded);
	if (spec->flags & minus)
	{
		expand_n(content, prefix, ft_slen(prefix));
		expand_n(content, expanded, explen);
		add_pad(content, spec, explen + 2);
	}
	else
	{
		spec->flags & zero ? expand_n(content, prefix, ft_slen(prefix)) : 0;
		add_pad(content, spec, ft_slen(expanded) + 2);
		!(spec->flags & zero) ? expand_n(content, prefix, ft_slen(prefix)) : 0;
		expand_n(content, expanded, ft_slen(expanded));
	}
	free(prefix);
	free(expanded);
}

void	put_written_chars(t_node **content, t_spec *spec)
{
	int	*expand;

	expand = get_next_arg(spec, NULL, NULL);
	*expand = (int)content_size(*content);
}

/*
** @brief         Insert ANSI escape codes for 8-bit colors. Available options:
**
**                {black}, {red}, {green}, {yellow},
**                {blue}, {magenta}, {cyan}, {nc}
**
** @param content The content arraylist
** @param format  The format string
**
** @return Length of format string to surpass
*/

size_t	colorize(t_node **content, const char *format)
{
	size_t	i;
	t_color	col;

	if (*format == '{')
	{
		i = 0;
		while (i < 8)
		{
			col = g_colors[i++];
			if (ft_startswith(format, col.color))
			{
				i = ft_slen(col.espace_seq);
				expand_n(content, col.espace_seq, i);
				return (ft_slen(col.color));
			}
		}
	}
	return (0);
}
