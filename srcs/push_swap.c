#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**argv;
	int		size;
	int		*nums;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	ft_define_size_array(ac, &argv, av, &size);
	if (ft_prepare_nums(size, argv, &stack_a, &nums))
	{
		//エラー処理がある
		// void	clear_argv(char **argv)
		return (EXIT);
	}
	if (size >= 2)
		ft_start_push_swap(&stack_a, size);
	return (EXIT);
}
