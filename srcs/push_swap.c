#include "push_swap.h"

int ft_count_array(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void ft_define_size_array(int ac, char ***argv, char **av, int *size)
{
	if (ac == 2)
	{
		*argv = ft_split(av[1], ' ');
		*size = ft_count_array(*argv);
	}
	else
	{
		*argv = &av[1];
		*size = ac - 1;
	}
}

int prepare_nums(int size, char **argv, t_list **stack_a, int **nums)
{
	if(!(ft_malloc_pp((void***)nums, sizeof(int) * (size + 1))))
		return (ERROR);
	if ((ft_check_arg(size, argv, stack_a, nums)))
	{
		write(2, "Error\n", 6);
		clear_stack_nums(*stack_a, *nums);
		return (1);
	}
	return(SUCCESS);
}

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
	if (prepare_nums(size, argv, &stack_a, &nums))
	{
		//エラー処理がある
		// void	clear_argv(char **argv)
		return (ERROR);
	}
	printf("size = %d\n", size);
	if (size >= 2)
		ft_start_push_swap(&stack_a, size);

	t_list mem;
	mem = *stack_a;
	while(mem.content != stack_a->next->content)
	{
		printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
		stack_a = stack_a->next;
	}
	printf("%d : %d : %d\n", stack_a->content, stack_a->prev->content, stack_a->next->content);
	return (EXIT);
}