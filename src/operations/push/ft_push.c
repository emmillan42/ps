/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:18:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 11:38:24 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(a, b);
	if (a->bench)
	{
		a->bench->pa_count++;
		a->bench->ops_count++;
	}
	if (a->print)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	ft_push(b, a);
	if (a->bench)
	{
		a->bench->pb_count++;
		a->bench->ops_count++;
	}
	if (a->print)
		write(1, "pb\n", 3);
}

/*
push first node from src to be the new b's first node.
src's second node becomes the new a's first node.
*/
void	ft_push(t_stack *dst, t_stack *src)
{
	t_node	*tmp;

	if (!src || !dst)
		return ;
	tmp = src->head;
	src->head = src->head->next;
	tmp->next = dst->head;
	tmp->prev = NULL;
	dst->head = tmp;
	if (dst->size == 0)
		dst->tail = tmp;
	dst->size++;
	src->size--;
}
