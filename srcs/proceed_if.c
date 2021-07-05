/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:04 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:05 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_proceed_if_smallest_a(t_list **stack_a, int size)
{
	int	smallest;
	int	new_size;
	int	i;

	i = 0;
	new_size = size;
	while (i < size)
	{
		smallest = ft_get_smallest(stack_a, new_size);
		if ((*stack_a)->content == smallest)
		{
			ft_r(stack_a, "ra");
			new_size--;
		}
		i++;
	}
	return (new_size);
}

int	ft_proceed_if_smallest(t_list **stack_a, t_list **stack_b, int size)
{
	int	smallest;
	int	i;
	int	new_size;

	i = 0;
	new_size = size;
	while (i < size)
	{
		if (!(*stack_b))
			smallest = ft_get_smallest(stack_a, size - i);
		else if (ft_get_smallest(stack_a, size - i) \
					< ft_get_smallest(stack_b, size))
			smallest = ft_get_smallest(stack_a, size);
		if ((*stack_a)->content == smallest)
		{
			ft_r(stack_a, "ra");
			new_size--;
		}
		else
			ft_p(stack_b, stack_a, "pb");
		i++;
	}
	return (new_size);
}
