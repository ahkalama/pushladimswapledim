/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:55:58 by ahkalama          #+#    #+#             */
/*   Updated: 2023/03/10 17:38:22 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void
	ft_push_swap(char *av[])
{
	t_stacks		stack; //stacklerin tanımlanması
	register int	size;
	register int	index;

	index = -1;
	size = ft_ps_strlen(av);
	stack.a = malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++index < size)
		stack.a[index] = ft_ps_atoi(av[index], stack.a);
	ft_check_repeat(stack.a, size);
	ft_sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int
	main(int ac, char *av[])
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		ft_push_swap(av);
		return (0);
	}
	return (0);
}
