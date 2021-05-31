/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:25:14 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/31 21:10:00 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t ft_get_smallest(t_list **stack, int n)
{
	int64_t smallest;
	t_list *ptr;
	int i;

	i = 1;
	smallest = (*stack)->content;
	ptr = (*stack)->next;
	while (i < n)
	{
		if (smallest > ptr->content)
			smallest = ptr->content;
		ptr = ptr->next;
		i++;
	}
	return (smallest);
}

int64_t ft_get_biggest(t_list **stack, int n)
{
	int64_t biggest;
	t_list	*ptr;
	int i;

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

void	ft_push(t_list **stack_a, t_list **stack_b, int size)
{
	while (size > 0)
	{
		ft_p(stack_a, stack_b, "pa");
		size--;
	}
}

void	ft_push_rotate(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		ft_p(stack_a, stack_b, "pa");
		ft_r(stack_a, "ra");
	}
}

static int ft_last_push(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
	if (size_a == 0)
	{
		ft_p(stack_a, stack_b, "pa");
		ft_r(stack_a, "ra");
		return (1);
	}
	else if (size_b == 0)
	{
		ft_r(stack_a, "ra");
		return (1);
	}
	return (0);
}

void ft_last_push_rotate(t_list **stack_a, t_list **stack_b, int size_a, int size_b)
{
	int count;
	int size;

	count = 0;
	size = size_a + size_b;
	while (count < size)
	{
		if(size_a == 0 || size_b == 0)
			ft_last_push(stack_a, stack_b, size_a, size_b);
		else if ((*stack_a)->content < (*stack_b)->content)
		{
			ft_r(stack_a, "ra");
			size_a--;
		}
		else
		{
			ft_p(stack_a, stack_b, "pa");
			ft_r(stack_a, "ra");
			size_b--;
		}
		count++;
	}
}
