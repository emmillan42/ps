/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 11:15:58 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		free(*stack);
		*stack = (tmp)->next;
	}
	free(stack);
}



void	ft_stackindex(t_stack *stack)
{
	int		less;
	t_stack	*tmp;

	while (stack != NULL)
	{
		if (stack)
			stack = stack->next;
	}
}

int	ft_issorted(t_stack *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_index(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	ft_indexrel(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}
