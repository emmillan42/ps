/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 19:41:06 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/27 19:41:25 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(void)
{
	char	*str;

	/* Test 1: prev == NULL */
	str = NULL;
	str = ft_strjoin_sep(str, "42");
	printf("Result 1: \"%s\"\n", str);

	/* Test 2: append another string */
	str = ft_strjoin_sep(str, "Madrid");
	printf("Result 2: \"%s\"\n", str);

	/* Test 3: append another string */
	str = ft_strjoin_sep(str, "Push_Swap");
	printf("Result 3: \"%s\"\n", str);

	/* Test 4: new == NULL */
	str = ft_strjoin_sep(str, NULL);
	printf("Result 4: \"%s\"\n", str);

	free(str);
	return (0);
}
