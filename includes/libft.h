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



typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

int					ft_abs(int n);
size_t				ft_strlen(const char *str);



char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);


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
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strtok(char *str, char *sep);
char				*ft_sjoin(int cnt, ...);
char				*ft_concat(char *s1, char *s2, t_bool and_free);
char				*ft_strtrunc(char *str, size_t len, t_bool and_free);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);
long int			ft_atol(const char *str);
long				ft_strtol(const char *str, char **endptr, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
t_bool				ft_isnumeric(char *str, size_t base);

int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_torot13(char *ac);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);

void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);

void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);

void				ft_putlst(t_list *lst);

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *lst_new);
void				ft_lstappend(t_list **alst, t_list *lst_new);
size_t				ft_lstsize(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstrev(t_list **alst);
void				ft_lstpush(t_list **head_ref, t_list *node);
void				ft_lstfree(void **acontent, size_t content_size);

wchar_t				*ft_strtoutf8(char *str);
char				*ft_wcrtomb(int c);
char				*ft_wcstombs(wchar_t *utf8str, int size);
size_t				ft_wcslen(const wchar_t *str);
size_t				ft_wcharlen(int c);

int					ft_ctoi_base(char c, const char *base);

size_t				ft_slen(const char *s);

t_bool				ft_startswith(const char *str, char *prefix);
t_bool				ft_endswith(const char *s, char *suffix);

void				ft_message_and_exit(char *message,
										int where, int exit_value);

#endif
