#include "push_swap.h"

void ft_rr(t_list **stack, char *str)
{
	//rra
	if (!((*stack) == NULL || (*stack)->next == NULL))
		*stack = (*stack)->prev;
	if (ft_strncmp(str, "rra", 4) == 0)
		write(1, "rra\n", 4);
	else if (ft_strncmp(str, "rrb", 4) == 0)
		write(1, "rrb\n", 4);
}

// void ft_rrr(t_all *all)
// {
// 	all->do_write = 0;
// 	ft_rra(all);
// 	ft_rrb(all);
// 	all->do_write = 1;
// 	if(all->do_write)
// 	{
// 		write(1, "rrr\n", 4);
// 		all->count++;
// 	}
// }