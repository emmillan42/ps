/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:40:49 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 15:07:40 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (1);
	a = NULL;
	b = NULL;
	if (!ft_valid_args(argc, argv))
		return (ft_return_error(1));
	if (!ft_parse_pushswap(&a, &b, argc, argv))
		return (ft_return_error(1));
	if (!ft_stacksorted(a))
		ft_sort_strategy(&a, &b);
	if (!!a->bench)
		ft_print_bench(a);
	return (ft_free_stack(a), ft_free_stack(b), 0);
}

int	ft_stacksorted(t_stack *stack)
{
	t_node	*head;
	t_node	*tmp;

	if (!stack)
		return (0);
	head = stack->head;
	while (head)
	{
		tmp = head;
		while (tmp)
		{
			if (head->value < tmp->value)
				return (0);
			tmp = tmp->next;
		}
		head = head->next;
	}
	return (1);
}
