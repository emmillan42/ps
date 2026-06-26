/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:39:01 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 13:20:50 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack	**stack, t_pushswap *pushswap)
{
	return ;
}

static void	ft_sort_three_helper(t_stack **stack, t_pushswap *pushswap)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	first = (*stack)->next;
	first = (*stack)->next->next;
	if (first->value > second->value && first->value > third->value)
	{
		ft_ra(stack, pushswap);
		if ((*stack)->value > (*stack)->next->value)
			ft_sa(stack, pushswap);
	}
	else if (second->value > first->value && second->value > third->value)
	{
		ft_rra(stack, pushswap);
		if ((*stack)->value > (*stack)->next->value)
			ft_sa(stack, pushswap);
	}
	else if (third->value > first->value && second->value > first->value)
		ft_sa(stack, pushswap);
}

void	ft_sort_three(t_stack **stack, t_pushswap *pushswap)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	first = (*stack)->next;
	first = (*stack)->next->next;
	if (ft_stacksorted(stack))
		return ;
	ft_sort_three_helper(stack, pushswap);
}

int main()
{
    char str[] = "a";
    char se1[] = "--simple";
    char se2[] = "--medium";
    char se3[] = "--complex";
    char se4[] = "--adaptive";
    int		arr[] = {3, 2, 1, 5, 97, 43, 6, 7, 42, 8};
    printf("Hello World %.2f\n", ft_compute_disorder(arr, (sizeof(arr) / sizeof(int))));
    printf("Hello World %d\n", strcmp(str, se1));

    return 0;
}
