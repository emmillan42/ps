/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 11:38:49 by durisosa         ###   ########.fr       */
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
	char	*strategy;
	char	*complexity;
	double	disorder;
}	t_benchmark;

typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_node	*target;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
	int			size;
	char		*strategy_arg;
	t_benchmark	*bench;
	int			print;
}	t_stack;


//ERRORS
int			ft_return_error(int print);
int			ft_exit_error(int code);

//PARSE UTILS
int			ft_valid_args(char **argv_split);
int			ft_parse_pushswap(t_stack **a, char **argv_split);
int			ft_parse_flags(t_stack *a, char **split);
int			ft_parse_integers(t_stack *a, char **split);
char		*ft_strjoin_args(int argc, char **argv);
char		*ft_strjoin_sep(char *prev, char *src);
void		ft_free_split(char **split);
int			ft_setflag_ps(t_stack *a, char *str);
int			ft_isflag_ps(char *str);
int			ft_valid_istr(char *istr);
double		ft_compute_disorder(t_stack *stack);
long		ft_atol(char *str);

//STACK UTILS
t_node		*ft_node_new(int value);
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
void		ft_stackadd_back(t_stack *stack, t_node *new);
void		ft_stackadd_front(t_stack *stack, t_node *new);

//BENCH_UTILS
t_benchmark	*ft_bench_new(void);
void		ft_bench_init(t_stack *a);
void		ft_bench_set_titles(t_benchmark *bench, char *s1, char *s2);
void		ft_bench_choose_strategy(t_benchmark *bench);
void		ft_print_bench(t_stack *stack);
void		ft_putdisorder_fd(double disorder, int fd);
void		ft_pulabel_fd(const char *label, int number, int fd);
void		ft_print_bench_fd(t_benchmark *bench, int fd);
void		print_ops_group1(t_benchmark *bench, int fd);
void		print_ops_group2(t_benchmark *bench, int fd);

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