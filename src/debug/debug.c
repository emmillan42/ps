/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:47:57 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/27 17:48:45 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printstack(t_stack *stack)
{
	int	count;

	count = 0;
	ft_printf("-------- begin of stack --------\n");
	while (stack->next != NULL)
	{
		ft_printf("[%d] stack node value is: '%d'\n", count, stack->value);
		stack = stack->next;
	}
	ft_printf("\n-------- end of stack --------");
}

void	ft_printstacks(t_stack *a, t_stack *b)
{
	ft_printstack(a);
	ft_printstack(b);
}
