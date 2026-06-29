/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 21:21:40 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_simple(t_stack **a, t_stack **b)
{
	return ;
}

static void	ft_sort_simple(t_stack **a, t_stack **b)
{
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b);
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b);
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b);
}

static void	ft_sort_complex(t_stack **a, t_stack **b)
{
}

void	ft_sort_strategy(t_stack **a, t_stack **b)
{
	return ;
}
