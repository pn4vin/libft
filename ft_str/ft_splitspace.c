/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:26:16 by ptyshevs          #+#    #+#             */
/*   Updated: 2019/01/17 00:45:16 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"

/*
** @brief      Counts the number of words in a string, delimited by the char c
**
** @param      s     String
** @param      c     Delimiter
**
** @return     Number of words.
*/

static size_t	count_words(const char *s)
{
	size_t	count;
	size_t	state;

	count = 0;
	state = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			state = 0;
		if (!ft_isspace(*s++) && (state = state == 0 ? 1 : 0))
			count++;
	}
	return (count);
}

/*
** @brief      Calculate length of the word, up until the next delimiter or
**             nul-terminator
**
** @param      s     String with the word starting at the index [0]
** @param      c     Delimiter
**
** @return     Length of the word
*/

static size_t	wordlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s && !ft_isspace(*s++))
		size++;
	return (size);
}

/*
** @brief      Free the memory allocated prior to malloc failure
**
** @param      atab  The address of tab - array of words
** @param      i     Index of element in which the allocation failed
**
** @return     NULL in appropriate format
*/

static char		**unleak(char ***atab, int i)
{
	while (--i > 0)
		free((*atab)[i]);
	free(*atab);
	return (NULL);
}

/*
** @brief      Create an array of strings obtained by splitting s by
**             ASCII whitespace characters
**
** @param      s     String to be splitted
** @param      c     Delimiter
**
** @return     Array of "words", or NULL if any of the memory allocations fails
*/

char			**ft_splitspace(const char *s)
{
	int		i;
	char	**tab;
	size_t	wlen;

	tab = NULL;
	if (s != NULL)
	{
		i = 0;
		if (!(tab = (char **)malloc(sizeof(char *) * (count_words(s) + 1))))
			return (NULL);
		while (*s)
		{
			while (ft_isspace(*s))
				s++;
			if ((wlen = wordlen(s)) > 0)
			{
				if (!(tab[i] = ft_strnew(wlen)))
					return (unleak(&tab, i));
				ft_strncpy(tab[i++], s, wlen);
				s = s + wlen;
			}
		}
		tab[i] = NULL;
	}
	return (tab);
}
