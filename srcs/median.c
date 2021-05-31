#include "push_swap.h"

int	ft_get_median(t_list *stack_a, int n, int minus)
{
	int		*nums;
	t_list	*ptr;
	int		i;
	int		median;

	ptr = stack_a;

	if(!(ft_malloc_p((void**)&nums, sizeof(int) * (n + 1))))
		return 0;
	nums[n] = 0;
	i = 0;
	while (i < n)
	{
		nums[i] = ptr->content;
		i++;
		ptr = ptr->next;
	}
	ft_quick_sort(nums, 0, n - 1);
	if (minus && n % 2 == 0)
		median = nums[n / 2 - 1];
	else
		median = nums[n / 2];
	ft_free_int(&nums);
	return (median);
}