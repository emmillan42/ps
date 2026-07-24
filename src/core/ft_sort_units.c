/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_units.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:39:01 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/24 00:00:58 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	t_node	*max;

	if (!a || a->size < 2 || ft_stacksorted(a))
		return ;
	if (a->size == 2)
	{
		ft_sa(a);
		return ;
	}
	max = find_max(a);
	if (max == a->head)
		ft_ra(a);
	else if (max == a->head->next)
		ft_rra(a);
	if (a->head->index > a->head->next->index)
		ft_sa(a);
}

void	ft_sort_four_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		move_min_to_top(a);
		ft_pb(a, b);
	}
	ft_sort_three(a);
	while (b->size > 0)
		ft_pa(a, b);
}

void	ft_sort_units(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		ft_sa(a);
	else if (a->size == 3)
		ft_sort_three(a);
	else if (a->size <= 5)
		ft_sort_four_five(a, b);
}
