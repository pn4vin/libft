/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 20:54:00 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/28 23:14:05 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @brief      Convert ASCII string to integer
**
**             1) Pass blanks at the beginning
**             2) Store sign
**             3) Read digits left-to-right
**
** @param      str   The string
**
** @return     integer
*/

int		ft_atoi(const char *str)
{
	int res;
	int sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13) || (res = 0) > 0)
		str++;
	sign = *str == '-' ? -1 : 1;
	*str == '+' || *str == '-' ? str++ : 0;
	while (*str >= 48 && *str <= 57)
		res = res * 10 + *str++ - '0';
	return (sign * res);
}
