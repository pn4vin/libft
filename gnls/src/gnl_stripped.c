/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:17:04 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/17 11:51:35 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnls.h"

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

static int		ft_parse_eof(char **str, char **line, ssize_t r)
{
	if (r == 0 && str && *str)
	{
		GNL_MALLCHECK((*line = ft_strsub(*str, 0, ft_slen(*str) + 1)));
		ft_strdel(str);
		return (1);
	}
	else if (r == 0)
		return ((int)(*line = NULL));
	return (-1);
}

/*
** @brief      Read line from the specified file descriptor
**
** @param      fds   Structure that contains buffer string associated with the
**                   file descriptor
** @param      line  pointer to the line location
**
** @return     the return code of the attempt to read a line from a file
*/

static int		ft_read_fd(int fd, char **line)
{
	char	*rem;
	char	*tmp;
	char	buf[GNL_BUFF_SIZE + 1];
	static	char *str = NULL;
	ssize_t	r;

	while (1)
	{
		if (str && (rem = ft_strchr(str, '\n')))
		{
			GNL_MALLCHECK((*line = ft_strsub(str, 0, rem - str)));
			tmp = ft_strsub(str, (rem - str) + 1, ft_slen(rem) + 1);
			ft_strdel(&str);
			return (tmp ? ((str) = tmp) != NULL : -1);
		}
		else
		{
			if (!(r = read(fd, buf, GNL_BUFF_SIZE)) || r == -1)
				return (ft_parse_eof(&str, line, r));
			buf[r] = '\0';
			GNL_MALLCHECK(tmp = ft_strjoin(str ? str : "", buf));
			ft_strdel(&str);
			str = tmp;
		}
	}
}

/*
** @brief      Stripped version of get_next_line designed to improve overall
 *             speed and efficiency.
 *
 *             Side effects:
 *                  if *line is not NULL, it is freed before processing
**
** @param      fd    File Descriptor
** @param      line  The line
**
** @return     1 - line has been read successfully
**             0 - EOF reached
**            -1 - error has happened
*/

int				ft_usgnl(const int fd, char **line)
{
	if (fd <= -1 || !line)
		return (-1);
	if (*line)
		ft_strdel(line);
	return (ft_read_fd(fd, line));
}
