#include "push_swap.h"

void ft_sort_five(t_list **stack_a, t_list **stack_b)
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
	// i = 0;
	// t_list *ptr;
	// ptr = (*stack_a)->next;
	// puts("-------a-----------");
	// printf("%d\n", (*stack_a)->content);
	// while ((*stack_a) != ptr)
	// {
	// 	printf("%d\n", ptr->content);
	// 	ptr = ptr->next;
	// }
	// puts("-------b-----------");
	// if ((*stack_b) != NULL)
	// {
	// 	printf("%d\n", (*stack_b)->content);
	// 	ptr = (*stack_b)->next;
	// 	while ((*stack_b) != ptr)
	// 	{
	// 		printf("%d\n", ptr->content);
	// 		ptr = ptr->next;
	// 	}
	// }
	ft_push_rotate(stack_a, stack_b);
}