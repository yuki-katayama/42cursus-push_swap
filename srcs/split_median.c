/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_median.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:37 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:38 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_median_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	median;
	int	split_size;
	int	i;

	median = ft_get_median(*stack_a, size, 1);
	split_size = ft_get_half_size(size);
	i = 0;
	while (i < split_size)
	{
		if ((*stack_a)->content <= median)
		{
			ft_p(stack_b, stack_a, "pb");
			i++;
		}
		else
			ft_r(stack_a, "ra");
	}
	return (0);
}

static void	ft_set_smallest(t_list **stack_b, int *smallest, \
								int smallest_b, int smallest_a)
{
	if (*stack_b && smallest_b < smallest_a)
		*smallest = smallest_b;
}

static void	ft_split_median_b2(t_list **stack_a, t_list **stack_b, \
								int *i, int median)
{
	if ((*stack_b)->content > median)
	{
		ft_p(stack_a, stack_b, "pa");
		(*i)++;
	}
	else
		ft_r(stack_b, "rb");
}

int	ft_split_median_b(t_list **stack_a, t_list **stack_b, \
								int size, int *proceed)
{
	int	median;
	int	split_size;
	int	smallest;
	int	i;

	*proceed = 0;
	median = ft_get_median(*stack_b, size, 1);
	split_size = size / 2;
	i = 0;
	smallest = ft_get_smallest(stack_b, size);
	while (i < split_size)
	{
		if (*proceed < ft_get_half_size(size) \
			&& (*stack_b)->content == smallest)
		{
			ft_p(stack_a, stack_b, "pa");
			ft_r(stack_a, "ra");
			ft_set_smallest(stack_b, &smallest, ft_get_smallest(stack_b, size), \
				ft_get_smallest(stack_a, (split_size - i)));
			(*proceed)++;
		}
		else
			ft_split_median_b2(stack_a, stack_b, &i, median);
	}
	return (median);
}
