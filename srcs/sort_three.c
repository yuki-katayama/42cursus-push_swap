/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:30 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:31 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_a(t_list **stack_a)
{
	int64_t	smallest;
	int64_t	biggest;

	smallest = ft_get_smallest(stack_a, 3);
	biggest = ft_get_biggest(stack_a, 3);
	if (biggest == (*stack_a)->next->content && smallest == (*stack_a)->content)
	{
		ft_s(stack_a, "sa");
		ft_r(stack_a, "ra");
	}
	else if (biggest == (*stack_a)->next->next->content \
			&& smallest == (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	else if (biggest == (*stack_a)->next->content \
			&& smallest == (*stack_a)->next->next->content)
		ft_rr(stack_a, "rra");
	else if (biggest == (*stack_a)->content \
			&& smallest == (*stack_a)->next->content)
		ft_r(stack_a, "ra");
	else if (biggest == (*stack_a)->content \
			&& smallest == (*stack_a)->next->next->content)
	{
		ft_s(stack_a, "sa");
		ft_rr(stack_a, "rra");
	}
}

void	ft_sort_three_b(t_list **stack_b)
{
	int64_t	smallest;
	int64_t	biggest;

	smallest = ft_get_smallest(stack_b, 3);
	biggest = ft_get_biggest(stack_b, 3);
	if (biggest == (*stack_b)->next->content && smallest == (*stack_b)->content)
	{
		ft_s(stack_b, "sb");
		ft_r(stack_b, "rb");
	}
	else if (biggest == (*stack_b)->next->next->content \
			&& smallest == (*stack_b)->next->content)
		ft_s(stack_b, "sb");
	else if (biggest == (*stack_b)->next->content \
			&& smallest == (*stack_b)->next->next->content)
		ft_rr(stack_b, "rrb");
	else if (biggest == (*stack_b)->content \
			&& smallest == (*stack_b)->next->content)
		ft_r(stack_b, "rb");
	else if (biggest == (*stack_b)->content \
			&& smallest == (*stack_b)->next->next->content)
	{
		ft_s(stack_b, "sb");
		ft_rr(stack_b, "rrb");
	}
}

void	ft_sort_three(t_list **stack_a, t_list **stack_b)
{
	ft_p(stack_b, stack_a, "pb");
	if ((*stack_a)->content < (*stack_a)->next->content)
		ft_r(stack_a, "ra");
	else
	{
		ft_s(stack_a, "sa");
		ft_r(stack_a, "ra");
	}
	if ((*stack_a)->content < (*stack_b)->content)
	{
		ft_r(stack_a, "ra");
		ft_p(stack_a, stack_b, "pa");
		ft_r(stack_a, "ra");
	}
	else
	{
		ft_p(stack_a, stack_b, "pa");
		ft_rotate(stack_a, 2, "ra");
	}
}

void	ft_sort_three_over(t_list **stack_a, t_list **stack_b)
{
	int	a_size;
	int	b_size;

	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	a_size = 2;
	b_size = 1;
	ft_last_push_rotate(stack_a, stack_b, a_size, b_size);
}
