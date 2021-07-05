/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:35 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:36 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_under_five_b(t_list **stack_a, t_list **stack_b, int size_b)
{
	if (size_b == 1)
		ft_push_rotate(stack_a, stack_b);
	else if (size_b == 2)
	{
		ft_sort_two(stack_b, "sb");
		ft_push_rotate(stack_a, stack_b);
	}
	else if (size_b == 3)
	{
		ft_sort_three_b(stack_b);
		ft_push_rotate(stack_a, stack_b);
	}
	else if (size_b == 4)
	{
		ft_push(stack_a, stack_b, 2, "pa");
		ft_sort_four_b(stack_a, stack_b);
	}
	else if (size_b == 5)
	{
		ft_push(stack_a, stack_b, 2, "pa");
		ft_sort_five_b(stack_a, stack_b);
	}
}

void	ft_sort_under_five_a(t_list **stack_a, t_list **stack_b, int size)
{
	size = ft_proceed_if_smallest_a(stack_a, size);
	if (size == 2)
	{
		ft_s(stack_a, "sa");
		ft_rotate(stack_a, size, "ra");
	}
	else if (size == 3)
		ft_sort_three(stack_a, stack_b);
	else if (size == 4)
		ft_sort_four(stack_a, stack_b, size);
	else if (size == 5)
	{
		size = ft_push_b_check_small(stack_a, stack_b, size, 3);
		if (size == 5)
			ft_sort_five_b(stack_a, stack_b);
		else if (size == 4)
			ft_sort_four_b(stack_a, stack_b);
		else if (size == 3)
			ft_sort_three_over(stack_a, stack_b);
		else if (size == 2)
		{
			ft_sort_two(stack_a, "sa");
			ft_rotate(stack_a, 2, "ra");
		}
	}
}
