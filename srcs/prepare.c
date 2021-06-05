#include "push_swap.h"

static int	ft_count_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

void	ft_define_size_array(int ac, char ***argv, char **av, int *size)
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

int	ft_prepare_nums(int size, char **argv, t_list **stack_a, int **nums)
{
	if (!(ft_malloc_pp((void***)nums, sizeof(int) * (size + 1))))
		return (ERROR);
	if ((ft_check_arg(size, argv, stack_a, nums)))
	{
		write(2, "Error\n", 6);
		clear_stack_nums(*stack_a, *nums);
		return (1);
	}
	return(SUCCESS);
}