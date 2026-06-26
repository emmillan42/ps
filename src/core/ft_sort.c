/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:04:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 12:27:10 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_sort_b(t_stack **a, t_pushswap *pushswap)
{
	t_stack	*b;

	b = NULL;
	while (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, &b, pushswap);
	return (b);
}

static void	ft_sort_big(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	return ;
}

void	ft_sort_simple(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	return ;
}