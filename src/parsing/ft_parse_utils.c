/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:19:24 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/27 19:29:49 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_sep(char *prev, char *new)
{
	char	*joined;
	size_t	prev_len;
	size_t	new_len;

	printf("join is %s", joined);
	if (!new)
		return (prev);
	if (!prev)
		prev_len = 0;
	else
		prev_len = ft_strlen(prev);
	new_len = ft_strlen(new);
	joined = malloc((prev_len + new_len + 2) * sizeof(char));
	if (!joined)
		return (free(prev), NULL);
	ft_strlcpy(joined, prev, prev_len);
	ft_strlcpy(joined + prev_len, " ", 1);
	ft_strlcpy(joined + prev_len + 1, new, new_len);
	if (prev != NULL)
		free(prev);

	printf("join is %s", joined);
	return (joined);
}

int	ft_find_bench(int argc, char **argv)
{
	return (0);
}

int	ft_valid_selector(char *str)
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

int	ft_duplicated(int *arr, int size)
{
	int	i;
	int	j;

	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
