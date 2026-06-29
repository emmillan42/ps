/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:02 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 21:37:10 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_benchmark	*ft_bench_new(void)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	ft_bzero(bench, sizeof(t_benchmark));
	return (bench);
}

void	ft_print_bench(t_stack *a)
{
	return ;
}