/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:55:24 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/02/11 11:22:13 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->len = 0;
	node->next = NULL;
	return (node);
}

/*
** @brief      Append string to the ArrayList
**
** @param      head    The head of the list
** @param      append  The append string
** @param      n       Number of bytes to append
*/

void	expand_n(t_node **head, const char *append, size_t n)
{
	t_node	*tmp;

	if (append == NULL)
		return ;
	if (!*head)
		*head = init_node();
	tmp = *head;
	while (n)
	{
		if (tmp->len < LSTCAP)
		{
			tmp->content[tmp->len++] = *append++;
			n--;
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
		{
			tmp->next = init_node();
			tmp = tmp->next;
		}
	}
}

/*
** @brief      Clean ArrayList
**
** @param      alst  The alst
*/

void	clean_lst(t_node **alst)
{
	t_node		*next;

	if (alst)
	{
		while (*alst)
		{
			next = (*alst)->next;
			free(*alst);
			*alst = next;
		}
	}
}

/*
** @brief      Calculate the total size of the content
**
** @param      head  The head
**
** @return     Total size
*/

size_t	content_size(t_node *head)
{
	size_t	size;

	size = 0;
	while (head && (size += head->len))
		head = head->next;
	return (size);
}

char	*collect_content(t_node *head)
{
	char	*collect;
	size_t	i;
	size_t	j;

	MALLCHECK(collect = ft_strnew(content_size(head)));
	j = 0;
	while (head)
	{
		i = 0;
		while (i < head->len)
		{
			collect[LSTCAP * j + i] = head->content[i];
			i++;
		}
		head = head->next;
		j++;
	}
	return (collect);
}
