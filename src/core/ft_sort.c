/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/03 22:17:28 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_adaptive_choice(t_stack *a, t_stack *b, double disorder)
{
	if (disorder < 0.2)
		ft_sort_simple(a, b);
	else if (disorder < 0.5)
		ft_sort_simple(a, b);
	else
		ft_sort_simple(a, b);
}

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	double	disorder;

	ft_print_stack(*a);
	if ((*a)->bench)
		disorder = (*a)->bench->disorder;
	else
		disorder = ft_compute_disorder(a);
	if (disorder == 0)
		return ;
	if ((*a)->size <= 5)
		ft_sort_units(a);
	else if (ft_strcmp((*a)->strategy_arg, "--simple") == 0)
		ft_sort_simple(*a, *b);
	else if (ft_strcmp((*a)->strategy_arg, "--medium") == 0)
		ft_sort_simple(*a, *b);
	else if (ft_strcmp((*a)->strategy_arg, "--complex") == 0)
		ft_sort_simple(*a, *b);
	else
		adaptive_choice(*a, *b, disorder);
	ft_print_stack(*a);
	return ;
}
