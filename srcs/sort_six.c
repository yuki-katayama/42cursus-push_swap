/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:29 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:30 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_six(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = 3;
	size_b = 3;
	ft_push(stack_a, stack_b, 3, "pb");
	ft_sort_three_a(stack_a);
	ft_sort_three_b(stack_b);
	ft_last_push_rotate(stack_a, stack_b, size_a, size_b);
}
