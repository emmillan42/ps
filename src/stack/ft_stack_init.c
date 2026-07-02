/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:36:34 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 11:17:25 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->bench = NULL;
	return (stack);
}

void	ft_stack_index(t_stack **stack)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	if (!stack)
		return ;
	i = 0;
	node = (*stack)->head;
	while (node != NULL)
	{
		tmp = node;
		i = 0;
		while (tmp != NULL)
		{
			if (tmp->value < node->value)
				i++;
			tmp = tmp->next;
		}
		node->index = i;
		node = node->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	if (!stack)
		return ;
	node = stack->head;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (stack->bench)
		free(stack->bench);
	free(stack);
}
