/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 02:15:30 by kyuki             #+#    #+#             */
/*   Updated: 2021/05/31 02:19:21 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long int	ft_atoi_ps(const char *str, int *err)
{
	long long int	res;
	int					negative;

	res = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' \
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	if (*str == '\0' || ft_isdigit(*str) == 0)
		*err = 1;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
		if ((negative == 1 && res > 2147483647) || (negative == -1 && res > 2147483648))
		{
			*err = 1;
			break ;
		}
	}
	if (*str != '\0')
		*err = 1;
	return (res * negative);
}

static int	ft_is_same_num(int **nums, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if ((*nums)[i] == (*nums)[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_check_arg(int size, char **argv, t_list **stack_a, int **nums)
{
	t_list *new;
	int err;
	int i;

	i = 0;
	err = 0;
	while(i < size)
	{
		(*nums)[i] = ft_atoi_ps(argv[i], &err);
		if (*stack_a == NULL)
		{
			*stack_a = ft_lstnew_ps((*nums)[i]);

		}
		else
		{
			new = ft_lstnew_ps((*nums)[i]);
			ft_lstadd_back_ps(stack_a, new);
		}
		if (err == 1)
			return (1);
		if (ft_is_same_num(nums, i) == 1)
			return (1);
		i++;
	}
	return (0);
}