/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:46:26 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/05 13:40:53 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_list **stack, char *str)
{
	if ((*stack)->content > (*stack)->next->content)
	{
		if (ft_strncmp(str, "sa", 3) == 0)
			ft_s(stack, "sa");
		else
			ft_s(stack, "sb");
	}
}
