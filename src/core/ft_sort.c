/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 12:24:52 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	if (ft_stacksize(a) > 3 && !ft_stacksorted(a))
		ft_pb(a, b);
	if (ft_stacksize(a) > 3 && !ft_stacksorted(a))
		ft_pb(a, b);
	if (ft_stacksize(a) > 3 && !ft_stacksorted(a))
		ft_pb(a, b);
}

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

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	return ;
}
