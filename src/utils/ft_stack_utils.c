/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:48:38 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 11:08:26 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **stack, t_stack *stack_new)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = stack_new;
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*new;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	new->value = value;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_stackappend(char *nbrstr, t_stack **a)
{
	int		n;
	t_stack	*last;
	t_stack	*new;

	if (!nbrstr || *nbrstr == '\0')
		ft_exit_error(1);
	if (!ft_valid_int(nbrstr))
		ft_exit_error(1);
	n = ft_atoi(nbrstr);
	if (!ft_int_range(n) || (a != NULL && ft_duplicated(a, n)))
		ft_exit_error(1);
	new = ft_stacknew(n);
	ft_lstadd_back(a, new);
}
