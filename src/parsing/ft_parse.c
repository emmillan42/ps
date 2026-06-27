/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:29:35 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/27 20:05:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

static void	ft_free_split(char **split)
{
	char	*tmp;

	if (!split)
		return ;
	while (*split)
	{
		tmp = *split;
		split++;
		free(tmp);
	}
}

static t_pushswap	*ft_find_selector(char **strs, t_pushswap **pushswap)
{
	int	found;
	int	i;

	found = 0;
	i = 0;
	while (strs[i])
	{
		if (ft_valid_selector(strs[i]))
		{
			if (found)
				return ((*pushswap)->valid = 0,
					(*pushswap)->error = "More than 1 valid selector",
					*pushswap);
			else
			{
				(*pushswap)->selector = strs[i];
				found = 1;
			}
		}
		i++;
	}
	if (!found)
		(*pushswap)->selector = "--adaptative";
}
static int	ft_count_valid_ints(char **strs)
{

}

static t_pushswap	*ft_split_numbers(char	**strs, t_pushswap *pushswap)
{
	int	i;
	int	count;
	int	*numbers;

	i = 0;
	count = 0;
	numbers = ft_count_valid_ints(strs);
	if (!pushswap)
		return (NULL);
	while (strs[i])
	{
		if (ft_valid_int(strs[i]))
		{
			numbers[count] = ft_atoi(strs[i]);
			count++;
		}
		else if (!ft_valid_selector(strs[i]))
			return (free(numbers), NULL);
		i++;
	}
	if (ft_duplicated(numbers, count))
		return ((*pushswap)->valid = 0, NULL);
	(*pushswap)->numbers_size = count;
	return (*pushswap);
}

static t_pushswap	*ft_pushswap_init(void)
{
	t_pushswap	*init;

	init = malloc(sizeof(t_pushswap));
	if (!init)
		return (NULL);
	init->joined_args = NULL;
	init->valid = 1;
	return (init);
}

t_pushswap	*ft_parse_pushswap(int argc, char **argv)
{
	t_pushswap	*pushswap;
	int			i;

	pushswap = ft_pushswap_init();
	if (!pushswap)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		pushswap->joined_args = ft_strjoin_sep(pushswap->joined_args, argv[i]);
		i++;
	}
	printf("joined is %s", pushswap->joined_args);
	if (!pushswap->joined_args)
		return (free(pushswap), NULL);
	printf("joined is %s", pushswap->joined_args);
	pushswap->splitted = ft_split(pushswap->joined_args, ' ');
	pushswap->numbers = ft_split_numbers(pushswap->splitted, &pushswap);
	pushswap = ft_find_selector(pushswap->splitted, &pushswap);
	pushswap->bench = ft_find_bench(argc, argv);
	if (!pushswap->valid)
		return (free(pushswap), NULL);
	return (pushswap);
}
