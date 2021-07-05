/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_five_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:22 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:23 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_define_size(int size, int *sizes_a, int *size_b, int i)
{
	sizes_a[0] = size / 2;
	*size_b = ft_get_half_size(size) - i;
	return (size / 2);
}

void	ft_define_size2(int size, int *sizes_a, int *size_b, int *size_remain)
{
	sizes_a[0] = size;
	*size_b = size;
	*size_remain = 0;
}

int	ft_count_five_size(int size)
{
	int	count;

	count = 0;
	while (size > 5)
	{
		size /= 2;
		count++;
	}
	return (count);
}

static int	ft_over_five_return(t_list **stack_a, t_list **stack_b, \
									int size, int *sizes_a)
{
	int	proceed;

	if (size > 5)
	{
		size = ft_proceed_if_smallest(stack_a, stack_b, size);
		sizes_a[0] = size / 2;
		proceed = 0;
		ft_split_median_b(stack_a, stack_b, size, &proceed);
		return (ft_get_half_size(size) - proceed);
	}
	else
	{
		sizes_a[0] = size;
		return (size);
	}
}

int	ft_over_five(t_list **stack_a, t_list **stack_b, int size)
{
	int	size_b;
	int	*sizes_a;
	int	i;

	size = ft_proceed_if_smallest_a(stack_a, size);
	if (size <= 5)
		ft_sort_under_five_a(stack_a, stack_b, size);
	else
	{
		i = ft_count_five_size(size);
		if (!(ft_malloc_p((void **)&sizes_a, sizeof(int) * i + 1)))
			return (1);
		size_b = ft_over_five_return(stack_a, stack_b, size, sizes_a);
		ft_over_five_repeat_in(stack_a, stack_b, sizes_a, size_b);
	}
	return (0);
}
