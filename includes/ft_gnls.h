/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnls.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 19:02:30 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/12/19 13:07:39 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNLS_H
# define FT_GNLS_H

# include <stdlib.h>
# include "libft.h"
# include "ft_memory.h"

# define GNL_BUFF_SIZE 1000
# define BUF_SIZE 1000
# define GNL_MALLCHECK(x) if (!(x)) return (-1);

typedef unsigned char		t_uc;

typedef struct		s_line
{
	t_uc			*str;
	size_t			len;
}					t_line;

typedef struct		s_fds
{
	char			*str;
	int				fd;
	struct s_fds	*next;
}					t_fds;

int					ft_sgnl(const int fd, char **line);
int					ft_gnl(int fd, char **line);
int					ft_gnl_v2(int fd, t_line *line, t_bool lb);
t_line				*init_line(void);
void				clean_t_line(t_line **line);
void				ft_tline_replace(t_line *dst, t_line *src);
void				ft_tline_join(t_line *left, t_line *right);
int					ft_gnw(int fd, char **word);

#endif
