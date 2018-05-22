/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 23:09:21 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/05/22 23:09:31 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TELL_H
#define FT_TELL_H

# include <stdlib.h>
# include <unistd.h>

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_panic(char *message, int where, int exit_value);

#endif
