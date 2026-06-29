/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:28:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 21:38:23 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
this function iterates over the command line arguments and
activate the flags that are found
errors like more than one flag or invalid flags are already checked
returns error if an invalid input is found, ignore numbers
*/
int	ft_parse_flags(t_stack **a, int argc, char **argv)
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
			if (!ft_parse_flags_split(a, split[j], &stop))
				return (ft_free_split(split), 0);
			j++;
		}
		ft_free_split(split);
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	ft_parse_flags_split(t_stack **a, char *str, int *stop)
{
	long	value;

	if (ft_isflag_pushswap(str))
		ft_stack_setflag(a, str);
	if ((*a)->strategy != NULL && (*a)->bench != NULL)
		*stop = 1;
	return (1);
}

void	ft_stack_setflag(t_stack **a, char *str)
{
	if (!a || !*a || !str)
		return ;
	if (ft_strcmp("--adaptive", str) == 0)
		ft_strlcpy((*a)->strategy, "--adaptive", 10);
	else if (ft_strcmp("--simple", str) == 0)
		ft_strlcpy((*a)->strategy, "--simple", 8);
	else if (ft_strcmp("--medium", str) == 0)
		ft_strlcpy((*a)->strategy, "--medium", 8);
	else if (ft_strcmp("--complex", str) == 0)
		ft_strlcpy((*a)->strategy, "--complex", 8);
	else if (ft_strcmp("--bench", str) == 0)
		ft_bench_init(a);
}

void	ft_bench_init(t_stack **a)
{
	if (!a || !*a)
		ft_exit_error(1);
	(*a)->bench = ft_bench_new();
	if (!(*a)->bench)
		ft_exit_error(1);
}
