/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:40:49 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/27 19:57:07 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_simple(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b, pushswap);
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b, pushswap);
	if (ft_stacksize(*a) > 3 && !ft_stacksorted(*a))
		ft_pb(a, b, pushswap);
}

static void	ft_sort_complex(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
}

static void	ft_select_sort(t_stack **a, t_stack **b, t_pushswap *pushswap)
{
	float	disorder;

	if (pushswap->numbers_size == 2)
	{
		return (ft_sa(a, pushswap));
	}
	else
	{
		b = malloc(sizeof(t_stack *));
		if (!b)
			return ;
		ft_pa(a, b, pushswap);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_pushswap	*pushswap;

	if (argc < 2)
		return (1);
	pushswap = NULL;
	a = NULL;
	b = NULL;
	pushswap = ft_parse_pushswap(argc, argv);
	if (!pushswap)
		return (1);
	a = ft_parse_stack(pushswap->numbers, pushswap->numbers_size);
	if (!a)
		return (free(pushswap), 1);
	if (!ft_stacksorted(a))
		ft_select_sort(&a, &b, pushswap);
	if (pushswap->bench)
		ft_print_bench(pushswap);
	return (ft_free_stack(&a), ft_free_stack(&b), free(pushswap), 0);
	return (0);
}
