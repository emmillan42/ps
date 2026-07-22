/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 23:19:14 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/22 22:57:11 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotation_cost(t_stack *stack, t_node *node)
{
	if (node->above_median)
		return (node->position);
	return (stack->size - node->position);
}

static int	combined_cost(int cost_self, int cost_target, int same_dir)
{
	if (same_dir)
	{
		if (cost_self > cost_target)
			return (cost_self);
		return (cost_target);
	}
	return (cost_self + cost_target);
}

void	update_costs_a(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		cs;
	int		ct;

	node = a->head;
	while (node)
	{
		cs = rotation_cost(a, node);
		if (node->target)
		{
			ct = rotation_cost(b, node->target);
			node->cost = combined_cost(cs, ct,
					node->above_median == node->target->above_median);
		}
		else
			node->cost = cs;
		node = node->next;
	}
}

void	update_costs_b(t_stack *a, t_stack *b)
{
	t_node	*node;
	int		cs;
	int		ct;

	node = b->head;
	while (node)
	{
		cs = rotation_cost(b, node);
		if (node->target)
		{
			ct = rotation_cost(a, node->target);
			node->cost = combined_cost(cs, ct,
					node->above_median == node->target->above_median);
		}
		else
			node->cost = cs;
		node = node->next;
	}
}
