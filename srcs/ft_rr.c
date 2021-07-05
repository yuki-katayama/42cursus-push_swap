/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:43:57 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:43:58 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_list **stack, char *str)
{
	if (!((*stack) == NULL || (*stack)->next == NULL))
		*stack = (*stack)->prev;
	if (ft_strncmp(str, "rra", 4) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(str, "rrb", 4) == 0)
		write(1, "rrb\n", 4);
}
