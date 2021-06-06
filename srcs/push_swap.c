#include "push_swap.h"

int main(int ac, char **av)
{
	t_list *stack_a;
	char **argv;
	int size;
	int *nums;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	ft_define_size_array(ac, &argv, av, &size);
	if (ft_prepare_nums(size, argv, &stack_a, &nums))
	{
		//エラー処理がある
		// void	clear_argv(char **argv)
		return (ERROR);
	}
	if (size >= 2)
		ft_start_push_swap(&stack_a, size);

	t_list mem;
	mem = *stack_a;
	while (mem.content != stack_a->next->content)
	{
		printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
		stack_a = stack_a->next;
	}
	printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
	return (EXIT);
}
