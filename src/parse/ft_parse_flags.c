/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:28:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 13:56:18 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function iterates over the command line arguments and
activate the flags that are found
errors like more than one flag or invalid flags are already checked
returns error if an invalid input is found, ignore numbers
*/
int	ft_parse_flags(t_stack **a, t_stack **b, int argc, char **argv)
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
			if (!ft_parse_flags_split(*a, *b, split[j], &stop))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_flags_split(t_stack *a, t_stack *b, char *str, int *stop)
{
	if (ft_isflag_pushswap(str))
	{
		if (!ft_parse_flags_setflag(a, b, str))
			return (0);
	}
	if (a->strategy != NULL && a->bench != NULL)
		*stop = 1;
	return (1);
}

int	ft_parse_flags_setflag(t_stack *a, t_stack *b, char *str)
{
	if (!a || !str)
		return (0);
	if (ft_strcmp("--adaptive", str) == 0)
		ft_stack_setstrategies(a, "adaptive", "adaptive");
	else if (ft_strcmp("--simple", str) == 0)
		ft_stack_setstrategies(a, "simple", "simple");
	else if (ft_strcmp("--medium", str) == 0)
		ft_stack_setstrategies(a, "medium", "medium");
	else if (ft_strcmp("--complex", str) == 0)
		ft_stack_setstrategies(a, "complex", "complex");
	else if (ft_strcmp("--bench", str) == 0)
	{
		if (!ft_bench_init(a, b))
			return (0);
	}
	return (1);
}

void	ft_stack_setstrategies(t_stack *a, char *s1, char *s2)
{
	if (!s1 || !s2)
		return ;
	ft_strlcpy(a->strategy_arg, s1, ft_strlen(s1));
	ft_strlcpy(a->strategy, s2, ft_strlen(s2));
}
