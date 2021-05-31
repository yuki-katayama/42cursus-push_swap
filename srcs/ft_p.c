#include "push_swap.h"

static void	ft_p2(t_list **stack_a, t_list *tmp, t_list *last)
{
	if (*stack_a == NULL)
	{
		*stack_a = tmp;
		(*stack_a)->next = *stack_a;
		(*stack_a)->prev = *stack_a;
	}
	else
	{
		last = (*stack_a)->prev;
		tmp->next = *stack_a;
		(*stack_a)->prev = tmp;
		tmp->prev = last;
		last->next = tmp;
		*stack_a = tmp;
	}
}

void ft_p(t_list **stack_a, t_list **stack_b, char *str)
{
	t_list *tmp;
	t_list *last;

	if (*stack_b == NULL)
		return ;
	tmp = *stack_b;
	last = (*stack_b)->prev;
	if ((*stack_b)->next == *stack_b)
		*stack_b = NULL;
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev =last;
		last->next = *stack_b;
	}
	ft_p2(stack_a, tmp, last);
	if (ft_strncmp(str, "pa", 3) == 0)
		write(1, "pa\n", 3);
	else if (ft_strncmp(str, "pb", 3) == 0)
		write(1, "pb\n", 3);
}
