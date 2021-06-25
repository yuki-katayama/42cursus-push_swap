/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:38:43 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/25 16:17:57 by kyuki            ###   ########.fr       */
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

void	ft_clear_stack_nums(t_list *stack_a, int *nums)
{
	ft_free_stack(stack_a);
	ft_free_int(&nums);
}

void	ft_clear_argv(int ac, char **argv)
{
	int	i;

	i = 0;
	if ((ac == 3) || ac == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			argv[i] = NULL;
			i++;
		}
		free(argv);
		argv = NULL;
	}
}
