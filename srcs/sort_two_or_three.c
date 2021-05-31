/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_or_three.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:24:15 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/31 18:18:23 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_two(t_list **stack, char *str)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		if (ft_strncmp(str, "sa", 3) == 0)
			ft_s(stack, "sa");
		else
			ft_s(stack, "sb");
	}
}

void	ft_sort_three_a(t_list **stack_a)
{
	int64_t smallest;
	int64_t biggest;
	smallest = ft_get_smallest(stack_a, 3);
	biggest = ft_get_biggest(stack_a, 3);
	if (biggest == (*stack_a)->next->content && smallest == (*stack_a)->content)
	{
		ft_s(stack_a, "sa");
		ft_r(stack_a, "ra");
	}
	else if (biggest == (*stack_a)->next->next->content && smallest == (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	else if (biggest == (*stack_a)->next->content && smallest == (*stack_a)->next->next->content)
		ft_rr(stack_a, "rra");
	else if (biggest == (*stack_a)->content && smallest == (*stack_a)->next->content)
		ft_r(stack_a, "ra");
	else if (biggest == (*stack_a)->content && smallest == (*stack_a)->next->next->content)
	{
		ft_s(stack_a, "sa");
		ft_rr(stack_a, "rra");
	}
}

void	ft_sort_three_b(t_list **stack_b)
{
	int64_t smallest;
	int64_t biggest;
	smallest = ft_get_smallest(stack_b, 3);
	biggest = ft_get_biggest(stack_b, 3);
	if (biggest == (*stack_b)->next->content && smallest == (*stack_b)->content)
	{
		ft_s(stack_b, "sb");
		ft_r(stack_b, "rb");
	}
	else if (biggest == (*stack_b)->next->next->content && smallest == (*stack_b)->next->content)
		ft_s(stack_b, "sb");
	else if (biggest == (*stack_b)->next->content && smallest == (*stack_b)->next->next->content)
		ft_rr(stack_b, "rrb");
	else if (biggest == (*stack_b)->content && smallest == (*stack_b)->next->content)
		ft_r(stack_b, "rb");
	else if (biggest == (*stack_b)->content && smallest == (*stack_b)->next->next->content)
	{
		ft_s(stack_b, "sb");
		ft_rr(stack_b, "rrb");
	}
}