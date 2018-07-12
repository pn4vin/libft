/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:11:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:22:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

/*
** @brief      Absolute value of the long long argument
**
** @param      value  The value
**
** @return     Absolute value
*/

long long	ft_labs(long long value)
{
	return (value < 0 ? -value : value);
}

/*
** @brief      Add padding to the placeholder
**
** @param      content  The content ArrayList
** @param      spec     The specifier
** @param      explen   Length of the expanded placeholder
*/

void		add_pad(t_node **content, t_spec *spec, size_t explen)
{
	char	*pad;
	size_t	n;
	size_t	i;

	if (spec->width > 0 && spec->width >= (int)explen)
	{
		n = spec->width - explen;
		pad = ft_strnew(n);
		i = 0;
		while (i < n)
		{
			if (!(spec->flags & minus))
				pad[i] = (char)(spec->flags & zero ? '0' : ' ');
			else
			{
				if (spec->flags & zero && !(spec->flags & minus))
					pad[i] = '0';
				else
					pad[i] = ' ';
			}
			i++;
		}
		expand_n(content, pad, n);
		free(pad);
	}
}

/*
** @brief      Get proper prefix for the unsigned number.
**
** @param      spec      The specifier
** @param      expanded  The expanded
** @param      nbr       The number
**
** @return     The prefix.
*/

char		*get_prefix(t_spec *spec, char *expanded, t_nbr nbr)
{
	char	*prefix;

	prefix = NULL;
	if (nbr.u > 0 || spec->type == 'p' || (spec->base == 8 && spec->prec > -1))
	{
		prefix = ft_strnew(2);
		if ((spec->type == 'p' || spec->flags & hash) &&
			(spec->base == 16 || spec->base == 8 || spec->base == 2))
			prefix[0] = '0';
		if (spec->type == 'p')
			prefix[1] = 'x';
		else if (spec->flags & hash)
		{
			if (spec->base == 16)
				prefix[1] = (char)(ft_isupper(spec->type) ? 'X' : 'x');
			else if (spec->base == 2)
				prefix[1] = (char)(ft_isupper(spec->type) ? 'B' : 'b');
		}
		if (spec->base == 8 && expanded[0] == '0')
			prefix[0] = '\0';
	}
	return (prefix);
}

/*
** @brief      Calculate the length of the resulting string, which is equivalent
**             to the size required to store it in the heap.
**
** @param      value  Value to be converted
** @param      base   The radix
**
** @return     The length
*/

static int	get_len(t_nbr nbr, int base, t_spec *spec, t_bool signed_num)
{
	int		len;

	len = nbr.i == 0 && spec->prec != 0 ? 1 : 0;
	if (signed_num)
	{
		while (nbr.i && ++len)
			if (!(nbr.i /= base))
				break ;
	}
	else
		while (nbr.u && ++len)
			if (!(nbr.u /= base))
				break ;
	len += spec->prec - len > 0 ? spec->prec - len : 0;
	return (len);
}

/*
** @brief      Convert number to unsigned string representation.
**
**             Base is expressed as an integer, from 2 to 36. The characters
**             comprising the base are the digits from range [0-9] and
**             upper-case letters [A-Z].
**
**             No control for the overflow or undeflow provided.
**
** @param      nbr         The number union
** @param      spec        The specifier
** @param      base        integer representation of the base
** @param      signed_nbr  Is this a signed number?
**
** @return     null-terminated string representation of the value provided
*/

char		*itoa_deluxe(t_nbr nbr, t_spec *spec, int base, t_bool signed_nbr)
{
	int		i;
	int		len;
	char	*str;

	len = get_len(nbr, base, spec, signed_nbr);
	MALLCHECK(str = ft_strnew(len));
	if ((i = 0) || signed_nbr)
		while (len > 0)
		{
			str[len-- - 1] = RADIX[ft_labs(nbr.i - (nbr.i / base * base))];
			spec->type >= 65 && spec->type <= 90 ? ft_toupper(str[len]) : 0;
			if (!(nbr.i /= base))
				break ;
		}
	else
		while (len > 0)
		{
			str[len-- - 1] = RADIX[nbr.u - (nbr.u / base * base)];
			ft_isupper(spec->type) ? str[len] = (char)ft_toupper(str[len]) : 0;
			if (!(nbr.u /= base))
				break ;
		}
	while (len > 0 && len > i)
		str[len-- - 1] = '0';
	return (str);
}
