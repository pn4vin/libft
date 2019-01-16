/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:46:42 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/17 00:40:04 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "ft_memory.h"
# include "ft_math.h"

/*
** Used with apostrophe (') to select appropriate separating character for
** thousands
*/

# include <locale.h>

/*
** Used in ft_fprintf (flopen, fclose) and in put_date (strftime)
*/

# include <stdio.h>

# define LSTCAP 50
# define CHECKSPECKLEN(x) if ((x) == 0) break;
# define MALLCHECK(x) if (!(x)) return (0);
# define RADIX "0123456789abcdefghijklmnopqrstuvwxyz"
# define FP_ACCURATE 1

/*
** Variadic functions - va_list struct and va_start/va_arg/va_end functions
*/

# include <stdarg.h>

/*
** ptrdiff_t data type for length field
*/

# include <stddef.h>
# include <stdint.h>
# include <time.h>

/*
** ===============================STRUCTURES====================================
*/

typedef struct	s_node
{
	char			content[LSTCAP];
	size_t			len;
	struct s_node	*next;
}				t_node;

typedef enum	e_flags
{
	none,
	minus,
	plus = 2,
	space = 4,
	zero = 8,
	hash = 16,
	apstr = 32
}				t_flags;

typedef enum	e_length
{
	l_none,
	hh,
	h,
	l,
	ll,
	j,
	z,
	t,
	L
}				t_length;

typedef struct	s_spec
{
	t_flags		flags;
	int			width;
	int			prec;
	t_length	length;
	int			pos;
	int			base;
	char		type;
}				t_spec;

typedef union	u_nbr
{
	unsigned long long	u;
	long long			i;
	double				d;
	float				f;
}				t_nbr;

typedef void	(*t_specptr)(t_node **content, t_spec *spec);

typedef struct	s_color
{
	char	*color;
	char	*espace_seq;
}				t_color;

static const t_color		g_colors[8] = {{"{black}", "\x1B[30m"},
	{"{red}", "\x1B[31m"}, {"{green}", "\x1B[32m"}, {"{yellow}", "\x1B[33m"},
	{"{blue}", "\x1B[34m"}, {"{magenta}", "\x1B[35m"}, {"{cyan}", "\x1B[36m"},
	{"{nc}", "\x1B[0m"}};

/*
** ===========================PROTOTYPES=======================================
*/

int				ft_printf(const char *format, ...);
int				ft_fprintf(FILE *stream, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
char			*ft_sprintf(const char *format, ...);
int				ft_vprintf(const char *format, va_list va_start);
int				ft_vdprintf(int fd, const char *format, va_list va_start);
char			*ft_vsprintf(const char *format, va_list va_start);
int				ft_arprintf(const char *format, ...);

char			*process_format(const char *format, t_node **content);

long long		ft_labs(long long value);
t_node			*init_node(void);
t_spec			*init_spec(t_spec *spec, const char *format, size_t speclen);

size_t			content_size(t_node *head);
void			expand_n(t_node **head, const char *append, size_t n);
char			*collect_content(t_node *head);
void			clean_lst(t_node **alst);
size_t			parse_specifier(const char *format);
ssize_t			get_int_length(ssize_t integer);
int				parse_pos(const char *format, int speclen);
t_bool			is_valid_type(int c);
size_t			colorize(t_node **content, const char *format);
t_nbr			*fetch_nbr(t_length len, char type, va_list arg, t_bool is_int);
t_nbr			*fetch_float(t_length length, va_list arg);
t_flags			parse_flags(const char *spec, size_t len);
int				parse_width(t_spec *spec, const char *str, size_t len);
int				parse_prec(t_spec *spec, const char *format, ssize_t len);
t_length		parse_length(const char *spec, ssize_t len);
void			*get_next_arg(t_spec *spec, va_list init, const char *format);
char			*get_prefix(t_spec *spec, char *expanded, t_nbr nbr);
char			*get_nonprintables(t_spec *spec, char *s);
size_t			nonprintable_size(char *s, t_bool cnt);
void			add_pad(t_node **content, t_spec *spec, size_t explen);

char			*itoa_deluxe(t_nbr nbr, t_spec *spec, int base, t_bool is_int);

void			put_integer(t_node **content, t_spec *spec);
void			put_uxob(t_node **content, t_spec *spec);
void			put_float(t_node **content, t_spec *spec);

void			put_string(t_node **content, t_spec *spec);
void			put_percent(t_node **content, t_spec *spec);
void			put_char(t_node **content, t_spec *spec);
void			put_written_chars(t_node **content, t_spec *spec);
void			put_nonprintable(t_node **content, t_spec *spec);
void			put_address(t_node **content, t_spec *spec);
void			put_date(t_node **content, t_spec *spec);
void			put_fd(t_node **content, t_spec *spec);
void			put_generic(t_node **content, t_spec *spec);

int				get_digit_exponent(double d);
void			extract_info(double d, int *sign, int *exponent,
							t_ull *mantissa);
void			preprocess(int *exponent, t_ull *mantissa);

char			*ft_dtoa(t_nbr nbr, t_spec *spec);
t_bigint		*float_convert(double d);
char			*d_round(char *s, int *digit_exponent, size_t prec);
char			*fp_format(t_nbr d, t_spec *spec);

#endif
