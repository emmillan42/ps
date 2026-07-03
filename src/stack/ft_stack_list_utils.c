/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_list_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:48:38 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/03 21:58:49 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*node;
	int		count;

	if (!stack)
		return ;
	count = 0;
	node = stack->head;
	ft_printf("\n-------- begin of stack --------\n");
	while (node)
	{
		ft_printf("[%d]: node value: %d\n", node->index, node->value);
		node = node->next;
	}
	ft_printf("\n-------- end of stack --------\n");
}

int	ft_stacksorted(t_stack *stack)
{
	t_node	*head;
	t_node	*tmp;

	if (!stack)
		return (1);
	head = stack->head;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			if (head->index > tmp->index)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
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

	if (!stack || !node)
		return ;
	new->prev = NULL;
	node = stack->head;
	new->next = node;
	if (!node)
		stack->tail = new;
	stack->head = new;
	stack->size++;
}
