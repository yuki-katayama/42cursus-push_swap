/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 03:02:46 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/30 15:26:50 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_ps(t_list *stack)
{
	int		i;
	t_list	*ptr;

	if (!stack)
		return (0);
	ptr = stack->next;
	i = 1;
	while (ptr != stack)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
