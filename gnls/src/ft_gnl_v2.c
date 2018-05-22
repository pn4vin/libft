/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_v2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:17:04 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/18 14:49:23 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnls.h>
#include "libft.h"

/*
** @brief      Initialize line
**
** @return     New t_line structure with fields initialized
*/

t_line		*init_line(void)
{
	t_line *line;

	line = (t_line *)malloc(sizeof(t_line));
	line->str = NULL;
	line->len = 0;
	return (line);
}

void		clean_t_line(t_line **line)
{
	if (*line)
		ft_memdel((void **)&(*line)->str);
	free(*line);
	*line = NULL;
}

/*
** @brief      Handle end-of-file properly
**
**             if file doesn't end with a newline, read the remaining characters
**             and return 1 - line was successfully read.
**             The next time one reads this file, it has ended - return 0 and
**             set *line to empty string.
**
** @param      fds   Current FD node in a linked list
** @param      line  The line
** @param      r     number of chars received by read(fd, buf) call
**
** @return     1  and remaining line if file doesn't end with newline
**             0  if file doesn't end with newline and was read completely
**             -1 in case of read() error
*/

static int	ft_parse_eof(t_line *buf, t_line *line, int r)
{
	if (r == 0 && buf->len)
	{
		line->len = buf->len;
		GNL_MALLCHECK((line->str = ft_memsub(buf->str, 0, buf->len, TRUE)));
		buf->len = 0;
		return (1);
	}
	else if (r == 0)
		return ((int)(NULL));
	return (-1);
}

/*
** @brief      Read line from the specified file descriptor
**
** @param      fds   Structure that contains buffer string associated with the
**                   file descriptor
** @param      line  pointer to the line location
** @param      lb    Whether to leave newline symbol in line or not
**
** @return     the return code of the attempt to read a line from a file
*/

static int	read_line(int fd, t_line *buf, t_line *line, t_bool lb)
{
	t_uc	*rem;
	t_uc	read_buf[GNL_BUFF_SIZE + 1];
	int		r;

	while (1)
	{
		if (buf->str && (rem = ft_memchr(buf->str, '\n', buf->len)))
		{
			line->str = ft_memsub(buf->str, 0, rem - buf->str + lb, FALSE);
			line->len = rem - buf->str + lb;
			buf->len = (buf->str + buf->len) - rem - 1;
			buf->str = ft_memsub(buf->str, rem - buf->str + 1, buf->len, TRUE);
			return (line->str ? line->str != NULL : -1);
		}
		else
		{
			if (!(r = (int)read(fd, read_buf, GNL_BUFF_SIZE)) || r == -1)
				return (ft_parse_eof(buf, line, r));
			buf->str = ft_memjoin(buf->str, buf->len, read_buf, (size_t)r);
			buf->len += r;
		}
	}
}

/*
** @brief      Gets the next line from the specified File Descriptor
**
** @param      fd    File Descriptor
** @param      line  The line structure
** @param      lb    Whether to leave newline symbol in line or not
**
** @return     1 - line has been read successfully
**             0 - EOF reached
**            -1 - error has happened
*/

int			ft_gnl_v2(const int fd, t_line *line, t_bool lb)
{
	static t_line	*buf;

	if (fd <= -1 || fd >= 65536)
		return (-1);
	if (line->str)
		ft_memdel((void **)&line->str);
	if (!buf)
		buf = init_line();
	return (read_line(fd, buf, line, lb));
}
