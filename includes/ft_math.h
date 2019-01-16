/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:16:50 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/06/28 18:17:55 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "libft.h"

/*
** Changing this is UB
*/

# define SPLIT_CONST	1000

/*
** This too
*/

# define SPOW		3
# define FP_EPS		0.00000001

typedef struct	s_bigint {
	int		sign;
	size_t	size;
	int		*arr;
}				t_bigint;

size_t			bi_usize(unsigned long long v);
size_t			bi_isize(long long v);
size_t			bi_dsize(double v);
size_t			bi_block_size(int b);

t_bigint		*bi_itobi(long long v);
t_bigint		*bi_utobi(unsigned long long v);
t_bigint		*bi_dtobi(double v);
t_bigint		*bi_stobi(char *v);

t_bigint		*bi_alloc(size_t size);
t_bigint		*bi_copy(t_bigint *bi);
t_bigint		*shrink_to_fit(t_bigint *a);

void			bi_prepend_blocks(t_bigint *bi, size_t n);
void			bi_append_blocks(t_bigint *bi, size_t n);
void			bi_end_cut(t_bigint *bi, size_t n);

char			*bi_tostr(t_bigint *bi);

t_bigint		*bi_add(t_bigint *a, t_bigint *b);
t_bigint		*bi_iadd(t_bigint *a, t_bigint *b);
t_bigint		*bi_increment(t_bigint *bi);

t_bigint		*bi_cmul(t_bigint *a, long long n);
t_bigint		*bi_mul(t_bigint *a, t_bigint *b);
t_bigint		*bi_imul(t_bigint *a, t_bigint *b);
t_bigint		*bi_pow(t_bigint *a, int n);

t_bigint		*bi_sub(t_bigint *a, t_bigint *b);
t_bigint		*bi_isub(t_bigint *a, t_bigint *b);

t_bigint		*bi_div(t_bigint *a, t_bigint *b);
t_bigint		*bi_idiv(t_bigint *a, t_bigint *b);

t_bigint		*bi_shift10(t_bigint *a, int shift);
t_bigint		*bi_ishift10(t_bigint *a, int shift);

t_bool			bi_gt(t_bigint *a, t_bigint *b);
t_bool			bi_ge(t_bigint *a, t_bigint *b);
t_bool			bi_eq(t_bigint *a, t_bigint *b);
t_bool			bi_lt(t_bigint *a, t_bigint *b);
t_bool			bi_le(t_bigint *a, t_bigint *b);
t_bool			bi_ceq(t_bigint *a, int b);

t_bigint		*bi_zero(void);
t_bigint		*bi_one(void);

void			bi_replace(t_bigint *a, t_bigint *b);
void			bi_release(t_bigint **abi);

long long		ft_pow(int base, int exponent);
double			ft_dpow(double base, int exponent);
double			ft_fabs(double d);
double			ft_floor(double v);

#endif
