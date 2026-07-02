/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:02 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 11:29:56 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_benchmark	*ft_bench_new(void)
{
	t_benchmark	*bench;

	bench = ft_calloc(1, sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	return (bench);
}


/*
This functions initializes additional metadata about the stack:
Disorder
Strategy used
Complexity Name
But strategy_used AND complexity depend on: strategy_arg if present.
if not strategy_arg > strategy equals adaptive
if strategy equals adaptive > names depend on disorder

conclusion: no strategy_arg > names depend on disorder
*/
void	ft_bench_init(t_stack *a)
{
	if (!a || !a->bench)
		return ;
	a->bench->disorder = ft_compute_disorder(a);
	if (!(a->strategy_arg) || ft_strcmp(a->strategy_arg, "--adaptive"))
		ft_bench_choose_strategy(a->bench);
	else if (ft_strcmp(a->strategy_arg, "--simple") == 0)
		ft_bench_set_titles(a->bench, "turk sort", "O(n²)");
	else if (ft_strcmp(a->strategy_arg, "--medium") == 0)
		ft_bench_set_titles(a->bench, "chunk_sort", "O(n√n)");
	else if (ft_strcmp(a->strategy_arg, "--complex") == 0)
		ft_bench_set_titles(a->bench, "radix sort", "O(n log n)");
}

void	ft_bench_set_titles(t_benchmark *bench, char *s1, char *s2)
{
	bench->strategy = ft_strdup(s1);
	bench->complexity = ft_strdup(s2);
}

void	ft_bench_choose_strategy(t_benchmark *bench)
{
	if (bench->disorder == 0)
		ft_bench_set_titles(bench, "stack already sorted", "no complexity");
	else if (bench->disorder < 0.2)
		ft_bench_set_titles(bench, "turk sort", "O(n²)");
	else if (bench->disorder < 0.5)
		ft_bench_set_titles(bench, "chunk sort", "O(n√n)");
	else
		ft_bench_set_titles(bench, "radix sort", "O(n log n)");
}

void	ft_print_bench(t_stack *a)
{
	if (!a)
		return ;
	return ;
}
