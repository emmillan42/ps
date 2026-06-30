/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/30 14:57:44 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

/*
	The selector is going to be found within the argv.
	If selector is given, strategy is going to be equal to it.
	If no selector is given it defaults to adaptive, which then
	selects a strategy (can only be simple, medium, or complex).
*/
typedef struct s_benchmark
{
	int		ops_count;
	int		pa_count;
	int		pb_count;
	int		sa_count;
	int		sb_count;
	int		ra_count;
	int		rb_count;
	int		rra_count;
	int		rrb_count;
	int		rr_count;
	int		ss_count;
	int		rrr_count;
}	t_benchmark;

typedef struct s_node
{
	long			value;
	long			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
	char		*strategy_arg;
	char		*strategy;
	char		*complexity;
	int			print;
	double		disorder;
	t_benchmark	*bench;
}	t_stack;

//PARSE UTILS
int			ft_return_error(int print);
int			ft_exit_error(int code);
void		ft_free_split(char **split);
int			ft_parse_pushswap(t_stack **a, t_stack **b, int argc, char **argv);
int			ft_valid_args(int argc, char **argv);
int			ft_valid_args_split(char *str, int *strategy_count);
double		ft_compute_disorder(t_stack *stack);
int			ft_parse_integers(t_stack **a, int argc, char **argv);
int			ft_parse_integers_split(t_stack *a, char *str, int *stop);
int			ft_duplicated(t_stack *a);
int			ft_parse_flags(t_stack **a, t_stack **b, int argc, char **argv);
int			ft_parse_flags_split(t_stack *a, t_stack *b,
				char *str, int *stop);
int			ft_parse_flags_setflag(t_stack *a, t_stack *b, char *str);
int			ft_isflag_pushswap(char *str);
int			ft_isstrategy(char *str);
int			ft_valid_istr(char *istr);
long		ft_atol(char *str);
int			ft_strcmp(char *s1, char *s2);

//STACK UTILS
t_node		*ft_node_new(int value, int index);
t_stack		*ft_stack_new(void);
void		ft_free_stack(t_stack *stack);
void		ft_print_stack(t_stack *stack);
void		ft_stack_index(t_stack **stack);
int			ft_stacksize(t_stack *stack);
int			ft_stacksorted(t_stack *stack);
t_node		*ft_stacklast(t_stack *stack);
int			ft_index(t_stack *stack, int target);
int			ft_indexrel(t_stack *stack, int target);
void		ft_stack_setstrategies(t_stack *a, char *s1, char *s2);
void		ft_stack_setnames(t_stack *a, char *s1, char *s2);
int			ft_stack_init(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_node *new);
void		ft_stackadd_front(t_stack **stack, t_node *new);

//BENCH_UTILS
t_benchmark	*ft_bench_new(void);
int			ft_bench_init(t_stack *a, t_stack *b);
void		ft_print_bench(t_stack *stack);

//SORT AND SORT UTILS
void		ft_sort_simple(t_stack *a, t_stack *b);
void		ft_sort_four(t_stack *a, t_stack *b);
void		ft_sort_five(t_stack *a, t_stack *b);
void		ft_sort_three(t_stack *stack);
void		ft_sort_strategy(t_stack **a, t_stack **b);
int			ft_max_index(t_stack *stack);
int			ft_min_index(t_stack *stack);

//OPERATIONS
void		ft_pa(t_stack *a, t_stack *b);
void		ft_pb(t_stack *a, t_stack *b);
void		ft_sa(t_stack *a);
void		ft_sb(t_stack *b);
void		ft_ra(t_stack *a);
void		ft_rb(t_stack *b);
void		ft_rra(t_stack *a);
void		ft_rrb(t_stack *b);
void		ft_ss(t_stack *a, t_stack *b);
void		ft_rr(t_stack *a, t_stack *b);
void		ft_rrr(t_stack *a, t_stack *b);

void		ft_push(t_stack *dest, t_stack *src);
void		ft_swap(t_stack *stack);
void		ft_rotate(t_stack *stack);
void		ft_reverse(t_stack *stack);

#endif