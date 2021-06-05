#include "push_swap.h"

void	ft_over_five_last(t_list **stack_a, t_list **stack_b, \
							int *sizes_a, int size_remain)
{
	if (size_remain > 0)
		ft_sort_over_five(stack_a, stack_b, size_remain, 0);
	ft_free_int(&sizes_a);
}

void	ft_over_five_repeat_in(t_list **stack_a, t_list **stack_b, \
								int *sizes_a, int size_b)
{
	int	i;
	int	proceed;

	i = 1;
	while (size_b > 5)
	{
		sizes_a[i] = size_b / 2;
		proceed = 0;
		ft_split_median_b(stack_a, stack_b, size_b, &proceed);
		size_b = ft_get_half_size(size_b) - proceed;
		i++;
	}
	ft_sort_under_five_b(stack_a, stack_b, size_b);
	i--;
	while (i >= 0)
	{
		ft_over_five(stack_a, stack_b, sizes_a[i]);
		i--;
	}
}
