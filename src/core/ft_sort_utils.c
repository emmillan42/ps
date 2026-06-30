/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:11:14 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 11:51:58 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
finds the maximum node->index within the given stack.

by: durisosa
*/
int	ft_max_index(t_stack *stack)
{
	t_node	*head;
	int		max;

	head = stack->head;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
}

/*
finds the minimum node->index within the given stack.

by: durisosa
*/
int	ft_min_index(t_stack *stack)
{
	t_node	*head;
	int		min;

	head = stack->head;
	min = head->index;
	while (head)
	{
		if (head->index > min)
			min = head->index;
		head = head->next;
	}
}
