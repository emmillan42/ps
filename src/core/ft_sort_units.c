/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_units.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:39:01 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/03 22:11:00 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_stack *a, t_stack *b)
{
	t_node	*head;
	int		min_index;

	head = a->head;
	min_index = ft_min_index(a);
	while (head->index != min_index)
		ft_ra(a);
	ft_pb(a, b);
	ft_sort_three(a);
	ft_pa(a, b);
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	t_node	*head;
	int		min_index;

	head = a->head;
	min_index = ft_min_index(a);
	while (head->index != min_index)
		ft_ra(a);
	ft_sort_four(a, b);
}

void	ft_sort_three(t_stack *stack)
{
	t_node	*head;
	int		max_index;

	head = stack->head;
	max_index = ft_max_index(stack);
	if (max_index == head->index)
	{
		ft_ra(stack);
		if (!ft_stacksorted(stack))
			ft_sa(stack);
	}
	else if (max_index == head->next->index)
	{
		ft_rra(stack);
		if (!ft_stacksorted(stack))
			ft_sa(stack);
	}
	else
		ft_sa(stack);
}

void	ft_sort_units(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		alg_two(a);
	else if (a->size == 3)
		alg_three(a);
	else if (a->size == 4)
		alg_four(a, b);
	else if (a->size == 5)
		alg_five(a, b);
}
