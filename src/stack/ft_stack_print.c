/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:21:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/24 14:38:33 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return ;
	node = stack->head;
	ft_printf("\n-------- begin of stack --------\n");
	while (node)
	{
		ft_printf("[%d]: node value: %d\n", node->index, node->value);
		node = node->next;
	}
	ft_printf("\n-------- end of stack --------\n");
}
