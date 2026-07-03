/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:39 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/03 22:24:11 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_stack *a, t_stack *b)
{
	t_node	*tmp;
	int		min_moves;

	if (a->size > 3 && !ft_stacksorte(a))
		ft_pb(a, b);
	if (a->size > 3 && !ft_stacksorte(a))
		ft_pb(a, b);
	while (a->size > 3 && !ft_stacksorte(a))
	{
		tmp = a->head;
		min_moves = ft_rrarrb_amount(a, b, tmp->index);
		return ;
	}
}
