/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:16:46 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/21 13:25:33 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# define MALLCHECK(x) if (!(x)) return (0);

typedef unsigned long long	t_ull;
typedef unsigned char		t_uc;



typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

int					ft_abs(int n);


int					ft_atoi(const char *str);
long int			ft_atol(const char *str);
long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);


t_bool				ft_isnumeric(char *str, size_t base);

int					ft_ctoi_base(char c, const char *base);


#endif
