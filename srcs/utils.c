/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:25:14 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/02 21:53:30 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int64_t ft_get_smallest(t_list **stack, int size)
{
	int64_t smallest;
	t_list *ptr;
	int i;

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

void	ft_push(t_list **stack_a, t_list **stack_b, int size, char *str)
{
	while (size > 0)
	{
		if (ft_strncmp(str, "pa", 3) == 0)
			ft_p(stack_a, stack_b, "pa");
		else if ((ft_strncmp(str, "pb", 3) == 0))
			ft_p(stack_b, stack_a, "pb");
		size--;
	}
}

void	ft_rotate(t_list **stack, int size, char *str)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strncmp(str, "ra", 3) == 0)
			ft_r(stack, "ra");
		else if (ft_strncmp(str, "rb", 3) == 0)
			ft_r(stack, "rb");
		i++;
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

int ft_push_b_check_small(t_list **stack_a, t_list **stack_b, int size, int count)
{
	int i;
	int new_size;
	int smallest;

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
