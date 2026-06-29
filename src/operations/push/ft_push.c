/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:18:59 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/29 20:59:39 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b)
{
	if (!b)
		return ;
	ft_push(a, b);
	if (a->bench)
		a->bench->pa_count++;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	if (!a)
		return ;
	ft_push(b, a);
	if (a->bench)
		a->bench->pb_count++;
	write(1, "pb\n", 3);
}

void	ft_push(t_stack *dest, t_stack *src)
{
	t_stack	*tmp;

	if (!src)
		return ;
}
