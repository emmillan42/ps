/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:39 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/03 22:25:22 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrarrb_amount(t_stack *a, t_stack *b, int index)
{


	if (a->size > 3 && !ft_stacksorte(a))
		ft_pb(a, b);
	if (a->size > 3 && !ft_stacksorte(a))
		ft_pb(a, b);
}


int	ft_cost_in_b(t_stack *b, int index_push)
{
	int		i;
	t_node	*tmp;

	if (index_push > b->head->index && index_push < b->tail->index)
		i = 0;
	else if (index_push > ft_max_index(b) || index_push < ft_min_index(b))
		i = ft_find_index(b, ft_max_index(b));
	else
	{
		i = 1;
		tmp = b->head;
		while (!(index_push < tmp && index_push > tmp->next))
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}
