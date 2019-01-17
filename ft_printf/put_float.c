/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:47:45 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/12 13:48:38 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_math.h"
#include "ft_printf.h"

/*
** @brief Using address of static variable was a stupid idea.
** This is nor thread-safe, nor could it be used recursively.
**
** @param length
** @param arg
** @return t_nbr *
*/

t_nbr	*fetch_float(t_length length, va_list arg)
{
	static t_nbr nbr;

	if (length == L)
		nbr.ld = va_arg(arg, long double);
	else
		nbr.d = va_arg(arg, double);
	return (&nbr);
}

char	*handle_special_cases(t_nbr nbr, t_spec *spec)
{
	t_ull	exponent;
	t_ull	mantissa;

	if (spec->length != L)
	{
		exponent = (nbr.u & (0x7FFl << 52)) >> 52;
		mantissa = nbr.u & (0xFFFFFFFFFFFFFull);
		if (exponent == 2047)
			return (ft_strdup((mantissa == 0 ? "inf" : "nan")));
	}
	else
	{
		exponent = (t_ull)((nbr.lu >> 64) & 0x3FFF);
		mantissa = (t_ull)(nbr.lu & (0x7FFFFFFFFFFFFFFFull));
		if (exponent == 16383)
			return (ft_strdup((mantissa == 0 ? "inf" : "nan")));
	}
	return (NULL);
}

char	*extract_sign(t_nbr nbr, t_spec *spec)
{
	t_ull	sign_bit;

	if (spec->length != L)
		sign_bit = (nbr.u >> 63) & 1;
	else
		sign_bit = (t_ull)((nbr.lu) >> 79) & 1;
	if (sign_bit)
		return ("-");
	else if (spec->flags & plus && spec->flags & space && nbr.d >= 0)
		return (" ");
	else if ((spec->flags & plus) && nbr.d >= 0)
		return ("+");
	return (NULL);
}

char	*float_preliminaries(t_nbr nbr, t_spec *spec)
{
	if (spec->prec == -1)
		spec->prec = 6;
	spec->flags &= spec->prec >= 0 ? ~zero : ~none;
	return (extract_sign(nbr, spec));
}

void	put_float(t_node **content, t_spec *spec)
{
	char	*expanded;
	char	*sign;
	t_nbr	nbr;

	nbr = *(t_nbr *)get_next_arg(spec, NULL, NULL);
	sign = float_preliminaries(nbr, spec);
	if (!(expanded = handle_special_cases(nbr, spec)))
		expanded = FP_ACCURATE ? fp_format(nbr, spec) : ft_dtoa(nbr, spec);
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
