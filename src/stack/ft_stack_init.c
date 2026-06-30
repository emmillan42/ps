/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:36:34 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 12:20:54 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_node_new(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->index = index;
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

t_stack	*ft_stack_new(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->bench = NULL;
	return (stack);
}

void	ft_stack_setflag(t_stack **a, char *str)
{
	if (!a || !*a || !str)
		return ;
	if (ft_strcmp("--adaptive", str) == 0)
		ft_strlcpy((*a)->strategy, "--adaptive", 10);
	else if (ft_strcmp("--simple", str) == 0)
		ft_strlcpy((*a)->strategy, "--simple", 8);
	else if (ft_strcmp("--medium", str) == 0)
		ft_strlcpy((*a)->strategy, "--medium", 8);
	else if (ft_strcmp("--complex", str) == 0)
		ft_strlcpy((*a)->strategy, "--complex", 8);
	else if (ft_strcmp("--bench", str) == 0)
		ft_strlcpy((*a)->strategy, "--bench", 7);
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

	node = stack->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	if (stack->bench)
		free(stack->bench);
	stack->bench = NULL;
	free(stack);
}
