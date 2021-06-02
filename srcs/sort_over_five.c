#include "push_swap.h"

static int ft_count_five_size(int size)
{
	int count;

	count = 0;
	while (size > 5)
	{
		size /= 5;
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
	return (proceed);
}

static int	ft_define_size(int size, int *sizes_a, int *size_b, int i)
{
	sizes_a[0] = size / 2;
	*size_b = ft_get_half_size(size) - i;
	return (size / 2);
}

void ft_over_five(t_list **stack_a, t_list **stack_b, int size)
{
	
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
	int remain_size;

	//5で何回割れたかを計算
	i = ft_count_five_size(size);
	if (!(ft_malloc_p((void **)&sizes_a, sizeof(int *) + (i + 1))))
		return (1);
	if (size > 5)
	{
		i = ft_stack_split(stack_a, stack_b, &size, first);
		remain_size = ft_define_size(size, sizes_a, &size_b, i);
		// printf("%d %d %d %d\n", remain_size, sizes_a[0], size_b, i);
	}
	ft_empty_b(stack_a, stack_b, sizes_a, &size_b);
	return (0);
}