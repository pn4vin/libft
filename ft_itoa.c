/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:45:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/29 21:45:00 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa(int n, int base)
{
	char *res;
	char *str = "0123456789abcdefghijklmnopqrstuvwxyz";

	int n_tmp = n;
	int new_len = 0;
	int i = 0;
	while (n_tmp >= base)
	{
		new_len++;
		n_tmp /= base;
	}
	new_len += n_tmp % base > 0 ? 1 : 0;
	res = (char *)malloc(sizeof(char) * (new_len + 1));
	i = 0;
	while (i < new_len)
		res[new_len - 1 - i++] = str[n % base];
	return (res);
}
