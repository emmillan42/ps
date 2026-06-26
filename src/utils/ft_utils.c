/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:15:54 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 11:42:20 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int error)
{
	if (error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else
		exit(0);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

float	ft_compute_disorder(int *numbers, int size)
{
	int	mistakes;
	int	total_pairs;
	int	i;
	int	j;

	i = -1;
	mistakes = 0;
	total_pairs = 0;
	while (++i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] > numbers[j])
				mistakes++;
			total_pairs++;
			j++;
		}
	}
}
