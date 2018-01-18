/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptyshevs <ptyshevs@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 21:34:13 by ptyshevs          #+#    #+#             */
/*   Updated: 2018/01/18 21:42:12 by ptyshevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unity.h"
#include "libft.h"


void	test_sjoin(void)
{
	char	*tmp;

	TEST_ASSERT_EQUAL_STRING((tmp = ft_sjoin(2, "hello", " world")), "hello world");
	free(tmp);
	TEST_ASSERT_EQUAL_STRING((tmp = ft_sjoin(1, "hello", " world")), "hello");
	free(tmp);
	TEST_ASSERT_EQUAL_STRING((tmp = ft_sjoin(11, "h", "e", "l", "l", "o", " ",
		"w", "o", "r", "l", "d")), "hello world");
	free(tmp);
	TEST_ASSERT_EQUAL_STRING((tmp = ft_sjoin(0, "hello", " world")), "");
	free(tmp);
}

int	main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_sjoin);

	return (UNITY_END());
}
