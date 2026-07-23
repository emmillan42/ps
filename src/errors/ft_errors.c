/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emmmilla <emmmilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:34:36 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/22 23:40:56 by emmmilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}

int	ft_return_error(int print)
{
	if (print)
		ft_putstr_fd("Error\n", 2);
	return (1);
}
