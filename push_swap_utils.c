/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:55:53 by ahkalama          #+#    #+#             */
/*   Updated: 2023/03/08 14:17:03 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_error(int *stack)
{
	free(stack);
	ft_printf("Error\n");
	exit (1);
}

void
	ft_check_repeat(int *stack, int size)
{
	register int	index;
	register int	jndex;

	index = 0;
	jndex = 1;
	while (index < size)
	{
		while (jndex < size)
		{
			if (stack[index] == stack[jndex])
				ft_error(stack);
			jndex++;
		}
		index++;
		jndex = index + 1;
	}
}

int
	ft_check_sorted(int *stack, int size, int order)
{
	register int	index;

	if (order == 0)
	{
		index = 0;
		while (index < size)
		{
			if (stack[index - 1] > stack[index])
				return (0);
			index++;
		}
		return (1);
	}
	else
	{
		index = 1;
		while (index < size)
		{
			if (stack[index - 1] < stack[index])
				return (0);
			index++;
		}
		return (1);
	}
}

int
	ft_ps_atoi(char *str, int *stack)
{
	unsigned int		i;
	register int		neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		ft_error(stack);
	return (num * neg);
}
