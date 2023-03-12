/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahkalama <@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:55:44 by ahkalama          #+#    #+#             */
/*   Updated: 2023/03/08 12:55:46 by ahkalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t
	ft_ps_strlen(char **str)
{
	register size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

size_t
	ft_strlen(const char *str)
{
	register size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t
	ft_strlcpy(char *dest, const char *src, size_t size)
{
	register size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index] != '\0')
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}

int
	ft_strcmp(const char *s1, const char *s2)
{
	register int	index;

	index = 0;
	if (!s1)
		return (0);
	while (s1[index] != '\0')
	{
		if (s1[index] != s2[index])
			return (0);
		index++;
	}
	return (1);
}
