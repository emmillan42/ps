/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nearly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:01:55 by emmmilla          #+#    #+#             */
/*   Updated: 2026/07/24 10:03:04 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mark_disordered(t_stack *a)
{
	t_node	*node;
	int		last;
	int		count;

	node = a->head;
	last = -1;
	count = 0;
	while (node)
	{
		if (node->index > last)
		{
			node->cheapest = false;
			last = node->index;
		}
		else
		{
			node->cheapest = true;
			count++;
		}
		node = node->next;
	}
	return (count);
}

static void	extract_phase(t_stack *a, t_stack *b, int total)
{
	while (total > 0)
	{
		if (a->head->cheapest)
			ft_pb(a, b);
		else
			ft_ra(a);
		total--;
	}
}

static void	reinsert_phase(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		update_positions(a);
		update_targets_b(a, b);
		bring_to_top(a, b->head->target);
		ft_pa(a, b);
	}
}

void	sort_nearly(t_stack *a, t_stack *b)
{
	int total;

	if (!a || a->size < 2)
		return ;
	total = a->size;
	if (mark_disordered(a) == 0)
		return ;
	extract_phase(a, b, total);
	reinsert_phase(a, b);
	final_rotation(a);
}
