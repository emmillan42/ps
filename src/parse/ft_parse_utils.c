/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:19:24 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 13:48:24 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **split)
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

int	ft_isflag_pushswap(char *str)
{
	size_t	strlen;

	if (!str)
		return (0);
	if (ft_strncmp(str, "--", 2) != 0)
		return (0);
	strlen = ft_strlen(str);
	if (ft_strncmp("--simple", str, strlen))
		return (1);
	else if (ft_strncmp("--medium", str, strlen))
		return (1);
	else if (ft_strncmp("--complex", str, strlen))
		return (1);
	else if (ft_strncmp("--adaptative", str, strlen))
		return (1);
	else if (ft_strncmp("--bench", str, strlen))
		return (1);
	else
		return (0);
}

int	ft_isstrategy(char *str)
{
	size_t	strlen;

	if (!str)
		return (0);
	if (ft_strncmp(str, "--", 2) != 0)
		return (0);
	strlen = ft_strlen(str);
	if (ft_strncmp("--simple", str, strlen))
		return (1);
	else if (ft_strncmp("--medium", str, strlen))
		return (1);
	else if (ft_strncmp("--complex", str, strlen))
		return (1);
	else if (ft_strncmp("--adaptative", str, strlen))
		return (1);
	else
		return (0);
}

int	ft_valid_istr(char *istr)
{
	int	i;

	i = 0;
	while (ft_isspace(istr[i]))
		i++;
	if (istr[i] == '-' || istr[i] == '+')
		i++;
	if (!istr[i] || !istr)
		return (0);
	while (istr[i])
	{
		if (!ft_isdigit(istr[i]))
			return (0);
		i++;
	}
	return (1);
}

double	ft_compute_disorder(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	double	mistakes;
	double	total_pairs;

	if (!stack || stack->size <= 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	current = stack->head;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs++;
			if (current->value > compare->value)
				mistakes++;
			compare = compare->next;
		}
		current = current->next;
	}
	return (mistakes / total_pairs);
}
