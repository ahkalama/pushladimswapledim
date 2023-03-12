/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_four.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:55:17 by ahkalama          #+#    #+#             */
/*   Updated: 2023/03/08 12:55:20 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_sa(t_stacks *stack, int print)
{
	register int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack A.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (print == 0)
		ft_printf("sa\n");
}

void
	ft_sb(t_stacks *stack, int print)
{
	register int	tmp;

	if (stack->size_b == 0 || stack->size_b == 1)
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in Stack B.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print == 0)
		ft_printf("sb\n");
}

void
	ft_ss(t_stacks *stack, int print)
{
	register int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| (stack->size_b == 0 || stack->size_b == 1))
	{
		if (print == 1)
			ft_printf("Nothing done. Very few numbers in stacks.\n");
		return ;
	}
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (print == 0)
		ft_printf("ss\n");
}
