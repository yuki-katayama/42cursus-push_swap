/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_ps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:30:25 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/30 13:59:56 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_ps(t_list **lst, t_list *new)
{
	t_list	*m;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	m = ft_lstlast_ps(*lst);
	m->next = new;
	(*lst)->prev = new;
	new->prev = m;
	new->next = *lst;
}