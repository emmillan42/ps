/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:48:38 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/24 14:37:11 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_stackadd_back(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	new->next = NULL;
	if (stack->size == 0)
	{
		stack->head = new;
		stack->tail = new;
		new->prev = NULL;
	}
	else
	{
		new->prev = stack->tail;
		stack->tail->next = new;
		stack->tail = new;
	}
	stack->size++;
}

void	ft_stackadd_front(t_stack *stack, t_node *new)
{
	t_node	*node;

	if (!stack || !new)
		return ;
	new->prev = NULL;
	node = stack->head;
	new->next = node;
	if (!node)
		stack->tail = new;
	stack->head = new;
	stack->size++;
}
