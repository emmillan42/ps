/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:29:35 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 14:58:56 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 


/*
This function is called after checking any invalid argument. 
It finds the flags that the user passes as arguments,
adaptive in case that no flag is found
bench mode if necessary

Put integers inside the stack until the first Non-integer value
if finds something Non-integer two things may happen: 
1. If it is a valid argument, stop without error
2. If it is not a valid argument, stop with error 
(but you are not supposed to have reached this point 
if that is the case)

it checks duplicated values inside the stack,
finally it initializes other stack info like strategy to be used,
complexity name,
and calculates disorder, which is going to be used by the
ft_sort function.
*/
int	ft_parse_pushswap(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	i;

	i = -1;
	(*a) = ft_stack_new();
	(*b) = ft_stack_new();
	if (!*a || !*b)
		return (free(*a), free(*b), 0);
	if (!ft_parse_flags(a, b, argc, argv))
		return (free(*a), free(*b), 0);
	if (!(*a)->strategy)
		ft_parse_flags_setflag(*a, *b, "--adaptive");
	if (!ft_parse_integers(a, argc, argv))
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
		*strategy_count = *strategy_count + 1;
	if (*strategy_count > 1)
		return (0);
	return (1);
}

/*
This functions initializes additional metadata about the stack:
Disorder
Strategy used
Complexity Name
But strategy_used AND complexity depend on: strategy_arg if present.
if not strategy_arg > strategy equals adaptive
if strategy equals adaptive > names depend on disorder

conclusion: no strategy_arg > names depend on disorder
*/
int	ft_stack_init(t_stack *a)
{
	if (!a)
		return (0);
	a->disorder = ft_compute_disorder(a);
	if (a->disorder == 0)
		ft_stack_setnames(a, "already sorted", "no complexity");
	else if (a->disorder < 0.2)
		ft_stack_setnames(a, "simple", "O(n²)");
	if (a->disorder == 0)
		ft_stack_setnames(a, "medium", "O(n√n)");
	if (a->disorder == 0)
		ft_stack_setnames(a, "complex", "O(n log n)");
	return (1);
}

void	ft_stack_setnames(t_stack *a, char *s1, char *s2)
{
	if (!s1 || !s2)
		return ;
	ft_strlcpy(a->strategy, s1, ft_strlen(s1));
	ft_strlcpy(a->complexity, s2, ft_strlen(s2));
}
