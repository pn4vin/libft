/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:17:04 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/12/24 22:05:02 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @brief      Add new File Descriptor to the list
**
** @param      afds  Pointer to the head of list
** @param      fd    File Descriptor
**
** @return     1, invariantly. -1 in case of malloc() failure
*/

static int		ft_fds_add(t_fds **afds, int fd)
{
	t_fds	*new;

	GNL_MALLCHECK((new = (t_fds *)malloc(sizeof(t_fds))));
	new->str = NULL;
	new->fd = fd;
	new->next = *afds;
	*afds = new;
	return (1);
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

static int		ft_parse_eof(t_fds *fds, char **line, int r)
{
	if (r == 0 && fds->str && *fds->str)
	{
		GNL_MALLCHECK((*line = ft_strsub(fds->str, 0, ft_slen(fds->str) + 1)));
		ft_strdel(&fds->str);
		return (1);
	}
	else if (r == 0)
		return ((*line = ft_strdup("")) ? 0 : -1);
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

static int		ft_read_fd(t_fds *fds, char **line)
{
	char	*rem;
	char	*tmp;
	char	buf[GNL_BUFF_SIZE + 1];
	ssize_t	r;

	while (1)
	{
		if (fds->str && (rem = ft_strchr((fds)->str, '\n')))
		{
			GNL_MALLCHECK((*line = ft_strsub(fds->str, 0, rem - fds->str)));
			tmp = ft_strsub(fds->str, (rem - fds->str) + 1, ft_slen(rem) + 1);
			ft_strdel(&fds->str);
			return (tmp ? ((fds->str) = tmp) != NULL : -1);
		}
		else
		{
			if (!(r = read(fds->fd, buf, GNL_BUFF_SIZE)) || r == -1)
				return (ft_parse_eof(fds, line, r));
			buf[r] = '\0';
			tmp = fds->str ? ft_strjoin((fds)->str, buf) : ft_strjoin("", buf);
			GNL_MALLCHECK(tmp);
			ft_strdel(&fds->str);
			fds->str = tmp;
		}
	}
}

/*
** @brief      Gets the next line from the specified File Descriptor
**             *line should be initialized.
**
** @param      fd    File Descriptor
** @param      line  The line
**
** @return     1 - line has been read successfully
**             0 - EOF reached
**            -1 - error has happened
*/

int				get_next_line(const int fd, char **line)
{
	static t_fds	*fds = NULL;
	t_fds			*tmp;

	if (fd <= -1 || !line)
		return (-1);
	tmp = fds;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if (ft_fds_add(&fds, fd) == -1)
			return (-1);
	}
	return (tmp ? ft_read_fd(tmp, line) : ft_read_fd(fds, line));
}
