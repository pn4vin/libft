/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:35:45 by ptyshevs          #+#    #+#             */
/*   Updated: 2017/10/29 12:41:43 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atol(const char *str)
{
	long int res;
	long int sign;
	long long min;
	long long max;

	max = 922337203685477580;

	while (*str == ' ' || (*str >= 9 && *str <= 13) || (res = 0) > 0)
		str++;
	sign = *str == '-' ? -1 : 1;
	*str == '+' || *str == '-' ? str++ : 0;
	while (*str >= 48 && *str <= 57)
	{
		if (res >= max && sign == 1)
			return (-1);
		else if (res >= max && sign == -1)
			return (0);
		res = res * 10 + *str++ - '0';
	}

	return (sign * res);
}

int 	ft_atoi_fixed(const char *str)
{
	return ((int)ft_atol(str));
}