/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:42:21 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/02 16:39:23 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_check_sorted(t_list *stack)
{
	t_list *ptr;
	ptr = stack;
	while (ptr->next != stack)
	{
		if (ptr->content < ptr->next->content)
			ptr = ptr->next;
		else
			return (0);
	}
	return (1);
}

void ft_start_push_swap(t_list **stack_a, int size)
{
	t_list *stack_b;
	stack_b = NULL;
	if (ft_check_sorted(*stack_a))
		return ;
	if (size == 2)
		ft_sort_two(stack_a, "sa");
	else if (size == 3)
		ft_sort_three_a(stack_a);
	else if (size == 4)
		ft_sort_four_a(stack_a, &stack_b);
	else if (size == 5)
		ft_sort_five_a(stack_a, &stack_b);
	else if (size == 6)
		ft_sort_six(stack_a, &stack_b);
	else if (size > 5)
		ft_sort_over_five(stack_a, &stack_b, size, 1);
}