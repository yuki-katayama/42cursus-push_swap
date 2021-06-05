#include "push_swap.h"

static int	ft_stack_split(t_list **stack_a, t_list **stack_b, \
							int *size, int first)
{
	int	proceed;

	proceed = 0;
	if (first)
		ft_split_median_a(stack_a, stack_b, *size);
	else
	{
		*size = ft_proceed_if_smallest(stack_a, stack_b, *size);
		ft_split_median_b(stack_a, stack_b, *size, &proceed);
	}
	return (proceed);
}

void	ft_empty_b(t_list **stack_a, t_list **stack_b, \
					int *sizes_a, int *size_b)
{
	int	i;
	int	proceed;

	i = 1;
	while (*size_b > 5)
	{
		sizes_a[i] = *size_b / 2;
		proceed = 0;
		ft_split_median_b(stack_a, stack_b, *size_b, &proceed);
		*size_b = ft_get_half_size(*size_b) - proceed;
		i++;
	}
	ft_sort_under_five_b(stack_a, stack_b, *size_b);
	i--;
	while (i > 0)
	{
		ft_over_five(stack_a, stack_b, sizes_a[i]);
		i--;
	}
}

int	ft_sort_over_five(t_list **stack_a, t_list **stack_b, int size, int first)
{
	int	i;
	int	size_b;
	int	*sizes_a;
	int	size_remain;

	size_remain = 0;
	if (size <= 5)
		ft_sort_under_five_a(stack_a, stack_b, size);
	else
	{
		puts("a");
		i = ft_count_five_size(size);
		if (!(ft_malloc_p((void **)&sizes_a, sizeof(int) + (i + 1))))
			return (1);
		if (size > 5)
		{
			i = ft_stack_split(stack_a, stack_b, &size, first);
			size_remain = ft_define_size(size, sizes_a, &size_b, i);
		}
		else
			ft_define_size2(size, sizes_a, &size_b, &i);
		ft_empty_b(stack_a, stack_b, sizes_a, &size_b);
		ft_over_five_last(stack_a, stack_b, sizes_a, size_remain);
	}
	return (0);
}
