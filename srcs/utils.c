/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:25:14 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/05 14:11:32 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t	ft_get_smallest(t_list **stack, int size)
{
	int64_t	smallest;
	t_list	*ptr;
	int		i;

	i = 1;
	smallest = (*stack)->content;
	ptr = (*stack)->next;
	while (i < size)
	{
		if (smallest > ptr->content)
			smallest = ptr->content;
		ptr = ptr->next;
		i++;
	}
	return (smallest);
}

int64_t	ft_get_biggest(t_list **stack, int n)
{
	int64_t	biggest;
	t_list	*ptr;
	int		i;

	i = 1;
	biggest = (*stack)->content;
	ptr = (*stack)->next;
	while (i < n)
	{
		if (biggest < ptr->content)
			biggest = ptr->content;
		ptr = ptr->next;
		i++;
	}
	return (biggest);
}

int	ft_push_b_check_small(t_list **stack_a, t_list **stack_b, \
							int size, int count)
{
	int	i;
	int	new_size;
	int	smallest;

	i = 1;
	new_size = size;
	smallest = ft_get_smallest(stack_a, size);
	ft_p(stack_b, stack_a, "pb");
	while (i < count)
	{
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

int	ft_get_half_size(int size)
{
	if (size % 2 == 0)
		return (size / 2);
	else
		return (size / 2 + 1);
}
