#include "push_swap.h"

void ft_r(t_list **stack, char *str)
{
	//ra
	if (!((*stack) == NULL || (*stack)->next == NULL))
		*stack = (*stack)->next;
	if (ft_strncmp(str, "ra", 3) == 0)
		write(1, "ra\n", 3);
	else if (ft_strncmp(str, "rb", 3) == 0)
		write(1, "rb\n", 3);
}

// void ft_rr(t_all *all)
// {
// 	all->do_write = 0;
// 	ft_ra(all);
// 	ft_rb(all);
// 	all->do_write = 1;
// 	if(all->do_write)
// 	{
// 		write(1, "rr\n", 3);
// 		all->count++;
// 	}
// }