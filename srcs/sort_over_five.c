#include "push_swap.h"

static int ft_count_five_size(int size)
{
	int count;

	count = 0;
	while (size > 5)
	{
		size /= 2;
		count++;
	}
	return (count);
}

static int ft_split_median_a(t_list **stack_a, t_list **stack_b, int size)
{
	int median;
	// int m_median;
	int split_size;
	int i;


	median = ft_get_median(*stack_a, size, 1);
	// m_median = ft_get_m_median(*stack_a, size);
	split_size = ft_get_half_size(size);
	i = 0;
	while (i < split_size)
	{
		if ((*stack_a)->content <= median)
		{
			ft_p(stack_b, stack_a, "pb");
			i++;
		}
		else
			ft_r(stack_a, "ra");
	}
	return (0);
}

void	ft_set_smallest(t_list **stack_b, int *smallest, int smallest_b, int smallest_a)
{
	if (*stack_b && smallest_b < smallest_a)
		*smallest = smallest_b;
}

static int ft_split_median_b(t_list **stack_a, t_list **stack_b, int size, int *proceed)
{
	int median;
	int split_size;
	int smallest;
	int i;

	*proceed = 0;
	median = ft_get_median(*stack_b, size, 1);
	split_size = size / 2;
	i = 0;
	smallest = ft_get_smallest(stack_b, size);
	while (i < split_size)
	{
		if (*proceed < ft_get_half_size(size) && (*stack_b)->content == smallest)
		{
			ft_p(stack_a, stack_b, "pa");
			ft_r(stack_a, "ra");
			(*proceed)++;
			ft_set_smallest(stack_b, &smallest, ft_get_smallest(stack_b, size), ft_get_smallest(stack_a, (split_size - i)));
		}
		else if ((*stack_b)->content > median)
		{
			ft_p(stack_a, stack_b, "pa");
			i++;
		}
		else
			ft_r(stack_b, "rb");
	}
	return (median);
}

static int ft_stack_split(t_list **stack_a, t_list **stack_b, int *size, int first)
{
	int proceed;

	proceed = 0;
	if(first)
		ft_split_median_a(stack_a, stack_b, *size);
	else
	{
		*size = ft_proceed_if_smallest(stack_a, stack_b, *size);
		ft_split_median_b(stack_a, stack_b, *size, &proceed);
	}
	return (proceed);
}

static int	ft_define_size(int size, int *sizes_a, int *size_b, int i)
{
	sizes_a[0] = size / 2;
	*size_b = ft_get_half_size(size) - i;
	return (size / 2);
}

static void ft_define_size2(int size, int *sizes_a, int *size_b, int *size_remain)
{
	sizes_a[0] = size;
	*size_b = size;
	*size_remain = 0;
}

int ft_proceed_if_smallest_a(t_list **stack_a, int size)
{
	int smallest;
	int new_size;
	int i;

	i = 0;
	new_size = size;
	while (i < size)
	{
		smallest = ft_get_smallest(stack_a, new_size);
		if ((*stack_a)->content == smallest)
		{
			ft_r(stack_a, "ra");
			new_size--;
		}
		i++;
	}
	return (new_size);
}

int ft_proceed_if_smallest(t_list **stack_a, t_list **stack_b, int size)
{
	int smallest;
	int i;
	int new_size;

	i = 0;
	new_size = size;
	while(i < size)
	{
		if(!(*stack_b))
			smallest = ft_get_smallest(stack_a, size - i);
		else if (ft_get_smallest(stack_a, size - i) < ft_get_smallest(stack_b, size))
			smallest = ft_get_smallest(stack_a, size);
		if ((*stack_a)->content == smallest)
		{
			ft_r(stack_a, "ra");
			new_size--;
		}
		else
			ft_p(stack_b, stack_a, "pb");
		i++;
	}
	return (new_size);
}

int ft_over_five_return(t_list **stack_a, t_list **stack_b, int size, int *sizes_a)
{
	int proceed;

	if (size > 5)
	{
		size = ft_proceed_if_smallest(stack_a, stack_b, size);
		sizes_a[0] = size / 2;
		proceed = 0;
		ft_split_median_b(stack_a, stack_b, size, &proceed);
		return (ft_get_half_size(size) - proceed);
	}
	else
	{
		sizes_a[0] = size;
		return (size);
	}
}

int ft_over_five(t_list **stack_a, t_list **stack_b, int size)
{
	int size_b;
	int *sizes_a;
	int i;

	size = ft_proceed_if_smallest_a(stack_a, size);
	if (size <= 5)
		ft_sort_under_five_a(stack_a, stack_b, size);
	else
	{
		i = ft_count_five_size(size);
		if (!(ft_malloc_p((void **)&sizes_a, sizeof(int) * i + 1)))
			return (1);
		size_b = ft_over_five_return(stack_a, stack_b, size, sizes_a);
		ft_over_five_repeat_in(stack_a, stack_b, sizes_a, size_b);
	}

	(void)stack_b;
	return 0;
}

void	ft_over_five_repeat_in(t_list **stack_a, t_list **stack_b, int *sizes_a, int size_b)
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

void	ft_empty_b(t_list **stack_a, t_list **stack_b, int *sizes_a, int *size_b)
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

int ft_sort_over_five(t_list **stack_a, t_list **stack_b, int size, int first)
{
	int i;
	int size_b;
	int *sizes_a;
	int size_remain;

	//5で何回割れたかを計算
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
			// printf("%d %d %d %d\n", remain_size, sizes_a[0], size_b, i);
		}
		else
			ft_define_size2(size, sizes_a, &size_b, &i);
		ft_empty_b(stack_a, stack_b, sizes_a, &size_b);
		ft_final(stack_a, stack_b, sizes_a, size_remain);
	}
	return (0);
}

void	ft_final(t_list **a, t_list **b, int *a_sizes, int remain_size)
{
	if (remain_size > 0)
		ft_sort_over_five(a, b, remain_size, 0);
	ft_free_int(&a_sizes);
}