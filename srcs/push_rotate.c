#include "push_swap.h"

void	ft_push(t_list **stack_a, t_list **stack_b, int size, char *str)
{
	while (size > 0)
	{
		if (ft_strncmp(str, "pa", 3) == 0)
			ft_p(stack_a, stack_b, "pa");
		else if ((ft_strncmp(str, "pb", 3) == 0))
			ft_p(stack_b, stack_a, "pb");
		size--;
	}
}

void	ft_rotate(t_list **stack, int size, char *str)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strncmp(str, "ra", 3) == 0)
			ft_r(stack, "ra");
		else if (ft_strncmp(str, "rb", 3) == 0)
			ft_r(stack, "rb");
		i++;
	}
}

void	ft_push_rotate(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
	{
		ft_p(stack_a, stack_b, "pa");
		ft_r(stack_a, "ra");
	}
}

static int	ft_last_push(t_list **stack_a, t_list **stack_b, \
							int size_a, int size_b)
{
	if (size_a == 0)
	{
		ft_p(stack_a, stack_b, "pa");
		ft_r(stack_a, "ra");
		return (1);
	}
	else if (size_b == 0)
	{
		ft_r(stack_a, "ra");
		return (1);
	}
	return (0);
}

void	ft_last_push_rotate(t_list **stack_a, t_list **stack_b, \
							 int size_a, int size_b)
{
	int	count;
	int	size;

	count = 0;
	size = size_a + size_b;
	while (count < size)
	{
		if (size_a == 0 || size_b == 0)
			ft_last_push(stack_a, stack_b, size_a, size_b);
		else if ((*stack_a)->content < (*stack_b)->content)
		{
			ft_r(stack_a, "ra");
			size_a--;
		}
		else
		{
			ft_p(stack_a, stack_b, "pa");
			ft_r(stack_a, "ra");
			size_b--;
		}
		count++;
	}
}
