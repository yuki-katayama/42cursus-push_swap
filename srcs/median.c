#include "push_swap.h"

int	ft_get_median(t_list *stack_a, int size, int minus)
{
	int		*nums;
	t_list	*ptr;
	int		i;
	int		median;

	ptr = stack_a;
	if (!(ft_malloc_p((void **)&nums, sizeof(int) * (size + 1))))
		return (0);
	nums[size] = 0;
	i = 0;
	while (i < size)
	{
		nums[i] = ptr->content;
		i++;
		ptr = ptr->next;
	}
	ft_quick_sort(nums, 0, size - 1);
	if (minus && size % 2 == 0)
		median = nums[size / 2 - 1];
	else
		median = nums[size / 2];
	ft_free_int(&nums);
	return (median);
}

// int	ft_get_m_median(t_list *stack_a, int size)
// {
// 	int		*nums;
// 	t_list	*ptr;
// 	int		i;
// 	int		m_median;

// 	ptr = stack_a;
// 	nums = (int *)malloc(sizeof(int) * (size + 1));
// 	nums[size] = 0;
// 	i = 0;
// 	while (i < size)
// 	{
// 		nums[i++] = ptr->content;
// 		ptr = ptr->next;
// 	}
// 	ft_quick_sort(nums, 0, size - 1);
// 	if (size % 2 == 0)
// 		i = size / 2;
// 	else
// 		i = size / 2 + 1;
// 	if (i % 2 == 0)
// 		m_median = nums[i / 2];
// 	else
// 		m_median = nums[i / 2 + 1];
// 	ft_free_int(&nums);
// 	return (m_median);
// }
