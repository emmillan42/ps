/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:48:38 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 14:57:31 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	count;

	count = 0;
	ft_printf("-------- begin of stack --------\n");

	ft_printf("\n-------- end of stack --------");
}

t_node	*ft_stacklast(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (NULL);
	node = stack->head;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_node	*node;

	if (stack == NULL)
		return (0);
	i = 0;
	node = stack->head;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **stack, t_node *new)
{
	t_node	*node;

	if (!stack || !*stack || !node)
		return ;
	new->prev = ft_stacklast(*stack);
	new->next = NULL;
	node = (*stack)->head;
	if (!node)
	{
		(*stack)->head = new;
		(*stack)->tail = new;
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
	(*stack)->size++;
}

void	ft_stackadd_front(t_stack **stack, t_node *new)
{
	t_node	*node;

	if (!stack || !*stack || !node)
		return ;
	new->prev = NULL;
	node = (*stack)->head;
	new->next = node;
	if (!node)
		(*stack)->tail = new;
	(*stack)->head = new;
	(*stack)->size++;
}
