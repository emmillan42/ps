/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:59:26 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/24 17:33:02 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace_str(const char *str)
{
	int	i;

	if (!str)
		return (1);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_valid_int(char *nbrstr)
{
	int	i;

	i = 0;
	if (nbrstr[i] == '-' || nbrstr[i] == '+')
		i++;
	if (!nbrstr[i] || !nbrstr)
		return (0);
	while (nbrstr[i])
	{
		if (!ft_isdigit(nbrstr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_int_range(long n)
{
	return (n >= INT_MIN && n <= INT_MAX);
}
