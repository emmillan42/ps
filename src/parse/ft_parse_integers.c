/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_integers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:59:26 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 14:57:02 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
creates an array of integers using an array of chars
ignores flags. Stops when find somethind that is not a number.

any invalid input was previously checked, so this function
assumes no invalid flags are present.
it fails if finds an invalid integer.
For example "--a" "+ maria", etc.

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo
*/
int	ft_parse_integers(t_stack **a, int argc, char **argv)
{
	char	**split;
	int		stop;
	int		i;
	int		j;

	i = 0;
	stop = 0;
	while (i < argc && !stop)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			return (ft_free_split(split), 0);
		j = 0;
		while (split[j] && !stop)
		{
			if (!ft_parse_integers_split(*a, split[j], &stop))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_integers_split(t_stack *a, char *str, int *stop)
{
	long	value;

	if (!ft_valid_istr(str) && !ft_isflag_pushswap(str))
		return (0);
	if (!ft_valid_istr(str))
		*stop = 1;
	value = ft_atol(str);
	if (!(value >= INT_MIN && value <= INT_MAX))
		return (0);
	ft_stackadd_back(&a, ft_node_new(value, 0));
	if (ft_duplicated(a))
		return (1);
	return (1);
}

int	ft_duplicated(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	if (!stack || !stack->head)
		return (0);
	current = stack->head;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
