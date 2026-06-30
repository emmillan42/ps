/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 17:32:43 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 12:10:06 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift all elements down by one position
//last becomes the first
void	ft_reverse(t_stack *stack)
{
	t_node	*new_last;
	t_node	*last;

	if (!stack || stack->size <= 1)
		return ;
	new_last = stack->head;
	while (new_last->next != NULL)
		new_last = new_last->next;
	last = stack->tail;
	last->next = stack->head;
	last->prev = NULL;
	stack->head->prev = last;
	stack->head = last;
}

void	ft_rra(t_stack *a)
{
	if (!a || a->size <= 1)
		return ;
	ft_reverse(a);
	if (a->bench)
	{
		a->bench->rra_count++;
		a->bench->ops_count++;
	}
	write(1, "rra\n", 3);
}

void	ft_rrb(t_stack *b)
{
	if (!b || b->size <= 1)
		return ;
	ft_reverse(b);
	if (b->bench)
	{
		b->bench->rrb_count++;
		b->bench->ops_count++;
	}
	write(1, "rrb\n", 3);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse(a);
	ft_reverse(b);
	if (a->bench)
	{
		a->bench->rrr_count++;
		a->bench->ops_count++;
	}
	write(1, "rrr\n", 3);
}
