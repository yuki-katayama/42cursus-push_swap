#include "push_swap.h"

void	ft_sort_under_five_b(t_list **stack_a, t_list **stack_b, int size_b)
{
	if (size_b == 1)
		ft_push_rotate(stack_a, stack_b);
	else if (size_b == 2)
	{
		ft_sort_two(stack_b, "sb");
		ft_push_rotate(stack_a, stack_b);
	}
	else if (size_b == 3)
	{
		ft_sort_three_b(stack_b);
		ft_push_rotate(stack_a, stack_b);
	}
	else if (size_b == 4)
	{
		ft_push(stack_a, stack_b, 2, "pa");
		ft_sort_four_b(stack_a, stack_b);
	}
	else if (size_b == 5)
	{
		ft_push(stack_a, stack_b, 2, "pa");
		ft_sort_five_b(stack_a, stack_b);
	}
}