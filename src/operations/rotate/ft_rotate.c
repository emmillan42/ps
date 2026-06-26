/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 10:32:48 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 10:49:41 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//shift everything 1 position to the top
//first becomes the last
void	ft_rb(t_stack	**b, t_pushswap *pushswap)
{
	t_stack	*tmp;

	if (!b || !*b || (*b)->next == NULL)
		return ;
	ft_rotate(b);
	pushswap->rb_count++;
	write(1, "rb\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_ra(t_stack	**a, t_pushswap *pushswap)
{
	t_stack	*tmp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	ft_rotate(a);
	pushswap->ra_count++;
	write(1, "ra\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_rr(t_stack **a, t_stack	**b, t_pushswap *pushswap)
{
	t_stack	*tmp;

	if (!a || !*a || (*a)->next == NULL)
		return ;
	if (!b || !*b || (*b)->next == NULL)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	pushswap->rr_count++;
	write(1, "rr\n", 3);
}

//shift everything 1 position to the top
//first becomes the last
void	ft_rotate(t_stack	**stack)
{
	t_stack	*tmp;

	if (!stack || !*stack || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next->next = NULL;
}
