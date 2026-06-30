/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:02 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 14:52:23 by durisosa         ###   ########.fr       */
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

int	ft_bench_init(t_stack *a, t_stack *b)
{
	t_benchmark	*bench;

	if (!a || !b)
		ft_exit_error(1);
	bench = ft_bench_new();
	if (!bench)
		return (0);
	a->bench = bench;
	b->bench = bench;
	return (1);
}

void	ft_print_bench(t_stack *a)
{
	return ;
}
