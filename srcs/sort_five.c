#include "push_swap.h"

void ft_sort_five_a(t_list **stack_a, t_list **stack_b)
{
	int median;
	int i;

	median = ft_get_median(*stack_a, 5, 1);
	i = 0;
	while (i < 2)
	{
		if ((*stack_a)->content > median)
		{
			ft_p(stack_b, stack_a, "pb");
			i++;
		}
		else
			ft_r(stack_a, "ra");
	}
	ft_sort_three_a(stack_a);
	ft_sort_two(stack_b, "sb");
	ft_push_rotate(stack_a, stack_b);
}

void	ft_sort_five_b(t_list **stack_a, t_list **stack_b)
{
	int	a_size;
	int	b_size;

	a_size = 2;
	b_size = 3;
	ft_sort_three_a(stack_a);
	ft_sort_two(stack_b, "sb");
	ft_last_push_rotate(stack_a, stack_b, a_size, b_size);
}