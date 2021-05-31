/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:45:12 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/31 17:40:39 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_four(t_list **stack_a, t_list **stack_b)
{
	int median;
	int i;

	i = 0;
	median = ft_get_median(*stack_a, 4, 0);
	while (i < 2)
	{
		if ((*stack_a)->content < median)
		{
			ft_p(stack_b, stack_a, "pb");
			i++;
		}
		else
			ft_r(stack_a, "ra");
	}
	
	// i = 0;
	// t_list *ptr;
	// ptr = (*stack_a)->next;
	// printf("%d\n", median);
	// puts("-------a-----------");
	// printf("%d\n", (*stack_a)->content);
	// while ((*stack_a) != ptr)
	// {
	// 	printf("%d\n", ptr->content);
	// 	ptr = ptr->next;
	// }
	// puts("-------b-----------");
	// if ((*stack_b) != NULL)
	// {
	// 	printf("%d\n", (*stack_b)->content);
	// 	ptr = (*stack_b)->next;
	// 	while ((*stack_b) != ptr)
	// 	{
	// 		printf("%d\n", ptr->content);
	// 		ptr = ptr->next;
	// 	}
	// }
	if ((*stack_a)->content > (*stack_a)->next->content && (*stack_b)->content < (*stack_b)->next->content)
		ft_s_s(stack_a, stack_b, "ss");
	else if ((*stack_a)->content > (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	else if ((*stack_b)->content < (*stack_b)->next->content)
		ft_s(stack_b, "sb");
	ft_push(stack_a, stack_b, 2);
}