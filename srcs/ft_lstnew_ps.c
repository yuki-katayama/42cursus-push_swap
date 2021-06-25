/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_ps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 13:18:42 by kyuki             #+#    #+#             */
/*   Updated: 2021/06/22 12:09:59 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_ps(int content)
{
	t_list	*new;

	new = NULL;
	if (!(ft_malloc_p((void **)&new, sizeof(t_list))))
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}
