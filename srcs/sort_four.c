#include "push_swap.h"

void	ft_sort_four_a(t_list **stack_a, t_list **stack_b)
{
	int	median;
	int	i;

	i = 0;
	median = ft_get_median(*stack_a, 4, 0);
	while (i < 2)
	{
		if ((*stack_a)->content < median)
		{
			ft_p(stack_b, stack_a, "pb");
			i++;
		}
		else
			ft_r(stack_a, "ra");
	}
	if ((*stack_a)->content > (*stack_a)->next->content \
		&& (*stack_b)->content < (*stack_b)->next->content)
		ft_s_s(stack_a, stack_b, "ss");
	else if ((*stack_a)->content > (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	else if ((*stack_b)->content < (*stack_b)->next->content)
		ft_s(stack_b, "sb");
	ft_push(stack_a, stack_b, 2, "pa");
}

void	ft_sort_four_b(t_list **stack_a, t_list **stack_b)
{
	int	size_a;
	int	size_b;

	size_a = 2;
	size_b = 2;
	if ((*stack_a)->content > (*stack_a)->next->content \
		&& (*stack_b)->content > (*stack_b)->next->content)
		ft_s_s(stack_a, stack_b, "ss");
	else if ((*stack_a)->content > (*stack_a)->next->content)
		ft_s(stack_a, "sa");
	else if ((*stack_b)->content > (*stack_b)->next->content)
		ft_s(stack_b, "sb");
	ft_last_push_rotate(stack_a, stack_b, size_a, size_b);
}

void	ft_sort_four(t_list **stack_a, t_list **stack_b, int size)
{
	size = ft_push_b_check_small(stack_a, stack_b, size, 2);
	if (size == 4)
		ft_sort_four_b(stack_a, stack_b);
	else if (size == 3)
		ft_sort_three_over(stack_a, stack_b);
	else if (size == 2)
	{
		ft_sort_two(stack_a, "sa");
		ft_rotate(stack_a, 2, "ra");
	}
}
