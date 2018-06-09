/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 16:11:58 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/05/26 16:13:20 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# include <stdlib.h>
# include "libft.h"

size_t				ft_slen(const char *s);
size_t				ft_strlen(const char *str);

char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_strcnt(char *str, char c);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strtok(char *str, char *sep);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_sjoin(int cnt, ...);
char				*ft_concat(char *s1, char *s2, t_bool and_free);
char				*ft_strtrunc(char *str, size_t len, t_bool and_free);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

t_bool				ft_startswith(const char *str, char *prefix);
t_bool				ft_endswith(const char *s, char *suffix);

wchar_t				*ft_strtoutf8(char *str);
char				*ft_wcrtomb(int c);
char				*ft_wcstombs(wchar_t *utf8str, int size);
size_t				ft_wcslen(const wchar_t *str);
size_t				ft_wcharlen(int c);

int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_torot13(char *ac);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);

t_bool				ft_strispaces(char *str);

#endif
