/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 21:00:18 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/13 21:01:23 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static t_bigint	*prep_rshift(t_bigint *a, int *shift, t_bigint **an)
{
	if (*shift < 0)
		return ((*an = bi_shift10(a, -*shift)));
	if (*shift > (int)(a->size * SPOW))
		return (bi_zero());
	*an = bi_copy(a);
	if (*shift >= SPOW)
	{
		bi_end_cut(*an, (size_t)(*shift / SPOW));
		*shift %= SPOW;
	}
	if (*shift == 0)
		return (*an);
	return (NULL);
}

/*
** @brief Right shift in decimal radix
**
** @param a
** @param shift
** @return t_bigint*
*/

t_bigint		*bi_rshift10(t_bigint *a, int shift)
{
	t_bigint	*n;
	int			carry;
	size_t		i;
	int			b;
	int			val;

	n = NULL;
	if (prep_rshift(a, &shift, &n))
		return (n);
	carry = 0;
	i = 0;
	shift = shift == 2 ? 100 : 10;
	while (i < n->size)
	{
		b = n->arr[i] / shift;
		val = b + carry;
		carry = n->arr[i] % shift;
		n->arr[i] = val;
		carry *= shift == 100 ? 10 : 100;
		i++;
	}
	return (n);
}

static t_bigint	*prep_shift(t_bigint *a, int *shift, t_bigint **an)
{
	if (*shift < 0)
		return (bi_rshift10(a, -*shift));
	*an = bi_copy(a);
	if (*shift >= 3)
	{
		bi_append_blocks(*an, (size_t)(*shift / SPOW));
		*shift %= SPOW;
	}
	if (*shift == 0)
		return (*an);
	return (NULL);
}

/*
** @brief Left shift in decimal radix
**
** @param a
** @param shift
** @return t_bigint*
*/

t_bigint		*bi_shift10(t_bigint *a, int shift)
{
	t_bigint	*n;
	int			carry;
	size_t		i;
	int			b;

	n = NULL;
	if (prep_shift(a, &shift, &n))
		return (n);
	carry = 0;
	i = n->size;
	shift = shift == 2 ? 100 : 10;
	while (i > 0)
	{
		b = n->arr[i - 1] * shift;
		n->arr[i - 1] = (b + carry) % SPLIT_CONST;
		carry = (b + carry) / SPLIT_CONST;
		i--;
	}
	if (carry != 0)
	{
		bi_prepend_blocks(n, 1);
		n->arr[0] = carry;
	}
	return (n);
}

/*
** @brief Inplace right (>0) or left (<0) shift
**
** @param a
** @param shift
** @return t_bigint*
*/

t_bigint		*bi_ishift10(t_bigint *a, int shift)
{
	t_bigint	*r;

	r = bi_shift10(a, shift);
	bi_replace(a, r);
	free(r);
	return (a);
}
