/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:55:11 by ahkalama          #+#    #+#             */
/*   Updated: 2023/03/08 12:55:14 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ft_sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, 0);
			else if (len++)
				ft_pa(stack, 0);
		}
	}
}

// ft_quicksort_3: Bu fonksiyon, yığın A'daki en fazla üç elemanı sıralar.
// Üç farklı durumu ele alır: len = 3 ve stack->size_a = 3 ise, stack->a'daki üç elemanı sıralar;
// len = 2 ise stack->a'daki iki elemanı sıralar; len = 3 ise, stack->a'daki üç elemanı sıralar.

int	ft_sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		ft_pa(s, 0);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s, 0);
		while (len--)
			ft_pa(s, 0);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				ft_sa(s, 0);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ft_push(s, len, 1);
			else
				ft_sb(s, 0);
		}
	}
	return (0);
}

int	ft_get_mediane(int *pivot, int *stack, int size)
{
	int	*tmp_stack;
	int	index;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	index = 0;
	while (index < size)
	{
		tmp_stack[index] = stack[index];
		index++;
	}
	ft_sort_tmp(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

// ft_get_mediane: Bu fonksiyon, bir dizinin ortanca elemanını hesaplar. 
// Dizinin ortanca elemanını bulmak için, 
// diziyi geçici bir diziye kopyalar, bu diziyi sıralar ve ardından ortanca elemanı belirler.

int	ft_quicksort_a(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (ft_check_sorted(stack->a, len, 0) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3(stack, len);
		return (1);
	}
	if (!ft_get_mediane(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			ft_pb(stack, 0);
		else if (++cnt)
			ft_ra(stack, 0);
	}
	while (items / 2 + items % 2 != stack->size_a && cnt--)
		ft_rra(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
	return (1);
}

// ft_quicksort_a: Bu fonksiyon, yığın A'daki elemanları sıralar. 
// Eğer yığın A'daki elemanlar zaten sıralıysa veya yalnızca üç veya daha az eleman varsa, sıralamayı tamamlar. 
//Aksi takdirde, bir pivot eleman seçer ve bu pivot etrafında elemanları iki alt diziye böler.

int	ft_quicksort_b(t_stacks *stack, int len, int cnt)
{
	int	pivot;
	int	items;

	if (!cnt && ft_check_sorted(stack->b, len, 1) == 1)
		while (len--)
			ft_pa(stack, 0);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ft_get_mediane(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			ft_pa(stack, 0);
		else if (++cnt)
			ft_rb(stack, 0);
	}
	while (items / 2 != stack->size_b && cnt--)
		ft_rrb(stack, 0);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}
// ft_quicksort_b: Bu fonksiyon, yığın B'deki elemanları sıralar. 
// Eğer yığın B'deki elemanlar zaten sıralıysa veya yalnızca üç veya daha az eleman varsa, 
// sıralamayı tamamlar. Aksi takdirde, bir pivot eleman seçer ve 
// bu pivot etrafında elemanları iki alt diziye böler. 
// Ardından bu iki alt diziyi sıralamak için kendi üzerinde yeniden çağrılır.

