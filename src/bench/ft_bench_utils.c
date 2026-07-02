/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: durisosa <durisosa@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:34:41 by durisosa          #+#    #+#             */
/*   Updated: 2026/07/02 11:13:25 by durisosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putdisorder_fd(double disorder, int fd)
{
	int	disorder_100;

	disorder_100 = (int)(disorder * 100 + 0.5);
	if (disorder_100 >= 100)
	{
		ft_putstr_fd("100.00%", fd);
		return ;
	}
	ft_putnbr_fd(disorder_100, fd);
	ft_putstr_fd(".00%", fd);
}

void	ft_pulabel_fd(const char *label, int number, int fd)
{
	ft_putstr_fd((char *)label, fd);
	ft_putnbr_fd(number, fd);
}

void	ft_print_bench_fd(t_benchmark *bench, int fd)
{
	if (bench)
		return ;
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putdisorder_fd(bench->disorder, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("[bench] strategy: ", fd);
	ft_putstr_fd(bench->strategy, fd);
	ft_putstr_fd(" / ", fd);
	ft_putstr_fd(bench->complexity, fd);
	ft_putchar_fd('\n', fd);
	ft_pulabel_fd("[bench] total_ops: ", bench->ops_count, fd);
	ft_putchar_fd('\n', fd);
	print_ops_group1(bench, fd);
	print_ops_group2(bench, fd);
}

void	print_ops_group1(t_benchmark *bench, int fd)
{
	ft_pulabel_fd("[bench]   sa: ", bench->sa_count, fd);
	ft_pulabel_fd("    sb: ", bench->sb_count, fd);
	ft_pulabel_fd("    ss: ", bench->ss_count, fd);
	ft_pulabel_fd("   pa: ", bench->pa_count, fd);
	ft_pulabel_fd("    pb: ", bench->pb_count, fd);
	ft_putchar_fd('\n', fd);
}

void	print_ops_group2(t_benchmark *bench, int fd)
{
	ft_pulabel_fd("[bench]   ra: ", bench->ra_count, fd);
	ft_pulabel_fd("    rb: ", bench->rb_count, fd);
	ft_pulabel_fd("    rr: ", bench->rr_count, fd);
	ft_pulabel_fd("  rra: ", bench->rra_count, fd);
	ft_pulabel_fd("   rrb: ", bench->rrb_count, fd);
	ft_pulabel_fd("   rrr: ", bench->rrr_count, fd);
	ft_putchar_fd('\n', fd);
}
