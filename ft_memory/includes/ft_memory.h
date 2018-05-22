/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 21:23:17 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/05/22 21:24:48 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
#define FT_MEMORY_H

# include <stdlib.h>
# include "libft.h"

# define MALLCHECK(x) if (!(x)) return (0);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memcpy_fwd(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memsub(void *s, size_t start, size_t len,
								t_bool and_free);

void				*ft_realloc(void *memloc, size_t old_size, size_t new_size,
					t_bool and_free);
void				*ft_memjoin(void *m1, size_t m1_len, void *m2,
								size_t m2_len);

#endif
