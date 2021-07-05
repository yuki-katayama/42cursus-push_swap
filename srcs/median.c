/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:00 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:01 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_median(t_list *stack_a, int size, int minus)
{
	int		*nums;
	t_list	*ptr;
	int		i;
	int		median;

	ptr = stack_a;
	if (!(ft_malloc_p((void **)&nums, sizeof(int) * (size + 1) * 2)))
		return (0);
	nums[size] = 0;
	i = 0;
	while (i < size)
	{
		nums[i] = ptr->content;
		i++;
		ptr = ptr->next;
	}
	ft_quick_sort(nums, 0, size - 1);
	if (minus && size % 2 == 0)
		median = nums[size / 2 - 1];
	else
		median = nums[size / 2];
	ft_free_int(&nums);
	return (median);
}
