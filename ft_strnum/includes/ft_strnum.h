/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnum.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 17:22:24 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/05/26 17:22:37 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRNUM_H
#define FT_STRNUM_H

#include "libft.h"

int					ft_abs(int n);

int					ft_atoi(const char *str);
long int			ft_atol(const char *str);

long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);

t_bool				ft_strisnum(char *str, size_t base);

int					ft_ctoi_base(char c, const char *base);

#endif
