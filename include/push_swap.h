/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:28:22 by durisosa          #+#    #+#             */
/*   Updated: 2026/06/26 18:11:34 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct t_pushswap
{
	char	*selector;
	char	*error;
	char	*joined_args;
	char	**splitted;
	char	**flags;
	int		*numbers;
	int		numbers_size;
	int		min_value;
	int		max_value;
	float	disorder;
	char	*complexity;
	int		valid;
	int		bench;
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
}	t_pushswap;

typedef struct s_stack
{
	long			value;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//STACK UTILS
void		ft_stackinit(t_stack **stack, int argc, char **argv);
t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
void		ft_stackadd_back(t_stack **stack, t_stack *stack_new);
void		ft_stackappend(char *nbrstr, t_stack **a);
int			ft_stacksize(t_stack *stack);
void		ft_free_stack(t_stack **stack);
int			ft_stacksorted(t_stack *stack);

//SORTING
void		ft_sort(t_stack **stack_a, t_stack **stack_b, t_pushswap *pushswap);
void		ft_sort_three(t_stack **stack_a, t_pushswap *pushswap);

//PUSHSWAP STRUCT
t_pushswap	*ft_parse_pushswap(int argc, char **argv);

//UTILS
void		ft_exit(int error);
void		ft_printstack(t_stack *stack);
int			ft_strcmp(char *s1, char *s2);
float		ft_compute_disorder(int *numbers, int size);

//STACK UTILS
t_stack		*ft_parse_stack(int *numbers, int numbers_size);
void		ft_stackadd_back(t_stack **stack, t_stack *stack_new);
t_stack		*ft_stacknew(int value);
t_stack		*ft_stacklast(t_stack *stack);
int			ft_stacksize(t_stack *stack);
void		ft_free_stack(t_stack **stack);
void		ft_stackindex(t_stack *stack);
int			ft_issorted(int *numbers, int size);
int			ft_index(t_stack *stack, int target);
int			ft_indexrel(t_stack *stack, int target);
void		ft_printstack(t_stack *stack);

//BENCH_UTILS
void		ft_print_bench(t_pushswap *pushswap);

//PARSE UTILS
int			ft_isspace(char c);
int			ft_isspace_str(const char *str);
int			ft_valid_int(char *nbrstr);
int			ft_int_range(long n);
char		*ft_strjoin_sep(char *prev, char *new);
int			ft_find_bench(int argc, char **argv);
int			ft_valid_selector(char *str);
int			ft_duplicated(int *arr, int size);

//OPERATIONS
void		ft_pa(t_stack **a, t_stack **b, t_pushswap *pushswap);
void		ft_pb(t_stack **a, t_stack **b, t_pushswap *pushswap);
void		ft_sa(t_stack **a, t_pushswap *pushswap);
void		ft_sb(t_stack **b, t_pushswap *pushswap);
void		ft_ra(t_stack **a, t_pushswap *pushswap);
void		ft_rb(t_stack **b, t_pushswap *pushswap);
void		ft_rra(t_stack **a, t_pushswap *pushswap);
void		ft_rrb(t_stack **b, t_pushswap *pushswap);
void		ft_ss(t_stack **a, t_stack **b, t_pushswap *pushswap);
void		ft_rr(t_stack **a, t_stack **b, t_pushswap *pushswap);
void		ft_rrr(t_stack **a, t_stack **b, t_pushswap *pushswap);
void		ft_push(t_stack **dest, t_stack **src);
void		ft_swap(t_stack **stack);
void		ft_rotate(t_stack **stack);
void		ft_reverse(t_stack **stack);

#endif