/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:33:48 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/31 13:16:57 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_quick_swap(int *nums, int *pl, int *pr, int x)
{
	while (nums[(*pl)] < x)
		(*pl)++;
	while (nums[(*pr)] > x)
		(*pr)--;
	if (*pl <= *pr)
	{
		ft_swap(&nums[*pl], &nums[*pr]);
		(*pl)++;
		(*pr)--;
	}
}

void	ft_quick_sort(int *nums, int left, int right)
{
	int	pl;
	int	pr;
	int	x;

	pl = left;
	pr = right;
	x = nums[(pl + pr) / 2];
	ft_quick_swap(nums, &pl, &pr, x);
	while (pl <= pr)
		ft_quick_swap(nums, &pl, &pr, x);
	if (left < pr)
		ft_quick_sort(nums, left, pr);
	if (pl < right)
		ft_quick_sort(nums, pl, right);
}
