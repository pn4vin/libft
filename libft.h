/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:16:46 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 20:59:54 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h> // Remove when submitting

size_t		ft_strlen(const char *str);

int			ft_atoi(const char *str);
int 		ft_atoi_fixed(const char *str);
long int	ft_atol(const char *str);
long		ft_strtol(const char *str, char **endptr, int base);
char		*ft_itoa(int n, int base);

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isspace(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

int		ft_ctoi_base(char c, const char *base);
char	ft_itoc_base(int i, const char*base);

#endif
