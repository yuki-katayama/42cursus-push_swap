#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**argv;
	int		size;
	int		*nums;
	int		argv_split;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	argv_split = ft_define_size_array(ac, &argv, av, &size);
	if (ft_prepare_nums(size, argv, &stack_a, &nums))
	{
		printf("%d : %d : %s\n", ac, size, argv[0]);
		if (argv_split == 1)
			ft_clear_argv(ac, argv);
		return (ERROR);
	}
	if (size >= 1)
	{
		ft_start_push_swap(&stack_a, size);
		ft_clear_stack_nums(stack_a, nums);
	}
	if (ac == 2)
		ft_clear_argv(ac, argv);
	return (EXIT);
}
