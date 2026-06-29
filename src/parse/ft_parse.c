/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:29:35 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 21:45:46 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	ft_parse_pushswap(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;

	i = -1;
	(*a) = ft_stacknew();
	(*b) = ft_stacknew();
	if (!*a || !*b)
		return (free(*a), free(*b), 0);
	if (!ft_parse_flags(a, argv, argc))
		return (free(*a), free(*b), 0);
	if (!(*a)->strategy)
		ft_stack_setflag(a, "adaptive");
	if (!ft_parse_integers(a, argv, argc))
		return (free(*a), free(*b), 0);
	if (ft_duplicated(*a))
		return (free(*a), free(*b), 0);
	if (!ft_stack_init(*a))
		return (free(*a), free(*b), 0);
	ft_print_stack(*a);
	return (1);
}

/*
HUGE RESPONSIBILITY ON THIS FUNCTION
Validate that we have received a valid input from the user.
Scenarios to contemplate:
./push_swap.out " 35 46 7   " 9 8 7 --simple
./push_swap.out 34 45  "" 9 8 7 " " "   " --> parse integers only until 45.
./push_swap.out 34 45  " 99 hola 3" 9 --> parse integers only until 99.
./push_swap.out "" "  " " 35 46 7  --complex " 9 8 7 

Example invalid inputs:

./push_swap.out a" 35 46 7   " 9 8 7 --simple
./push_swap.out d d ewa
./push_swap.out --complex 9 8 7 Hola mundo

For each argv, split it in case it is a quoted string, iterate
over the split to check if an invalid input is found.

by: durisosa
*/
int	ft_valid_args(int argc, char **argv)
{
	char	**split;
	int		strategy_count;
	int		i;
	int		j;

	i = 0;
	strategy_count = 0;
	while (i < argc && strategy_count < 2)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[i])
			return (0);
		j = 0;
		while (split[j])
		{
			if (!ft_valid_args_split(split[j], &strategy_count))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_valid_args_split(char *str, int *strategy_count)
{
	if (!ft_isflag_pushswap(str) && !ft_valid_istr(str))
		return (0);
	if (ft_isstrategy(str))
		*strategy_count++;
	if (strategy_count > 1)
		return (0);
	return (1);
}

int	ft_stack_init(t_stack **a)
{
	if (!a || !*a)
		return (0);
	(*a)->disorder = ft_compute_disorder(*a);
	if ((*a)->disorder == 0)
		ft_stack_set_strategies(a, "already sorted", "no complexity");
	return (1);
}

void	ft_stack_set_strategies(t_stack **a, char *strategy, char *complexity)
{
	if (!a || !*a || !strategy || !complexity)
		return ;
	ft_strlcpy((*a)->strategy, strategy, ft_strlen(strategy));
	ft_strlcpy((*a)->strategy, complexity, ft_strlen(complexity));
}
