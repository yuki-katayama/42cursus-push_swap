#include "push_swap.h"

void ft_s(t_list **stack, char *str)
{
	// sa
	if (!((*stack) == NULL || (*stack)->next == NULL))
		ft_swap(&(*stack)->content, &(*stack)->next->content);
	if (ft_strncmp(str, "sa", 3) == 0)
		write(1, "sa\n", 3);
	else if (ft_strncmp(str, "sb", 3) == 0)
		write(1, "sb\n", 3);
}

void ft_s_s(t_list **stack_a, t_list **stack_b, char *str)
{
	ft_s(stack_a, str);
	ft_s(stack_b, str);
	if (ft_strncmp(str, "ss", 3) == 0)
		write(1, "ss\n", 3);
}

// void ft_ss(t_all *all)
// {
// 	all->do_write = 0;
// 	ft_sa(all);
// 	ft_sb(all);
// 	all->do_write = 1;
// 	if(all->do_write)
// 	{
// 		write(1, "ss\n", 3);
// 		all->count++;
// 	}
// }