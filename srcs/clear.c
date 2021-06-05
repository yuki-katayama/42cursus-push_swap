/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:38:43 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/05 12:57:24 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_list *stack)
{
	t_list	*p;
	int		size;
	int		i;

	if (!stack)
		return ;
	size = ft_lstsize_ps(stack);
	i = 0;
	while (i < size)
	{
		p = stack;
		stack = stack->next;
		if (p)
			free(p);
		p = NULL;
		i++;
	}
	stack = NULL;
}

void	clear_stack_nums(t_list *stack_a, int *nums)
{
	ft_free_stack(stack_a);
	ft_free_int(&nums);
}
