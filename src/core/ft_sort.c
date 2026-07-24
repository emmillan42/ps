/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/23 21:23:53 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_stack **a, t_stack **b)
{
	if ((*a)->size <= 5)
		ft_sort_units(*a, *b);
	else if ((*a)->strategy_used == STRAT_SIMPLE)
		sort_insertion(*a, *b);
	else if ((*a)->strategy_used == STRAT_MEDIUM)
		sort_chunk(*a, *b);
	else if ((*a)->strategy_used == STRAT_COMPLEX)
		sort_radix(*a, *b);
	else
		sort_turk(*a, *b);
}

static t_strategy	ft_adaptive_choice(t_stack *a)
{
	if (a->disorder < 0.2)
		return (STRAT_SIMPLE);
	if (a->disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_TURK);
}

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	(*a)->strategy_used = (*a)->strategy_arg;
	(*a)->disorder = ft_compute_disorder(*a);
	if ((*a)->strategy_used == STRAT_ADAPTIVE)
		(*a)->strategy_used = ft_adaptive_choice(*a);
	run_strategy(a, b);
}
