/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/24 10:17:33 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_stack **a, t_stack **b)
{
	if ((*a)->size <= 5)
		ft_sort_units(*a, *b);
	else if ((*a)->strategy_used == STRAT_SIMPLE)
		sort_insertion(*a, *b);
	else if ((*a)->strategy_used == STRAT_NEARLY)
		sort_nearly(*a, *b);
	else if ((*a)->strategy_used == STRAT_MEDIUM)
		sort_chunk(*a, *b);
	else if ((*a)->strategy_used == STRAT_COMPLEX)
		sort_turk(*a, *b);
	else
		sort_radix(*a, *b);
}

static t_strategy	ft_adaptive_choice(t_stack *a)
{
	if (a->disorder < 0.2)
		return (STRAT_NEARLY);
	if (a->disorder < 0.5)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	(*a)->strategy_used = (*a)->strategy_arg;
	(*a)->disorder = ft_compute_disorder(*a);
	if ((*a)->strategy_used == STRAT_ADAPTIVE)
		(*a)->strategy_used = ft_adaptive_choice(*a);
	run_strategy(a, b);
}
