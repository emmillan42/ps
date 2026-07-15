/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_small_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 20:46:08 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/15 15:32:42 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	if (!stack || !stack->head)
		return (NULL);
	max = stack->head;
	node = max->next;
	while (node)
	{
		if (node->index > max->index)
			max = node;
		node = node->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	if (!stack || !stack->head)
		return (NULL);
	min = stack->head;
	node = min->next;
	while (node)
	{
		if (node->index < min->index)
			min = node;
		node = node->next;
	}
	return (min);
}

static void	move_min_to_top(t_stack *a)
{
	t_node	*min;
	int		rotations;

	update_positions(a);
	min = find_min(a);
	rotations = min->position;
	if (rotations <= (a->size - 1) / 2)
		while (rotations--)
			ft_ra(a);
	else
	{
		rotations = a->size - rotations;
		while (rotations--)
			ft_rra(a);
	}
}
