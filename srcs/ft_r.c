/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:43:56 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:43:57 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r(t_list **stack, char *str)
{
	if (!((*stack) == NULL || (*stack)->next == NULL))
		*stack = (*stack)->next;
	if (ft_strncmp(str, "ra", 3) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(str, "rb", 3) == 0)
		write(1, "rb\n", 3);
}
