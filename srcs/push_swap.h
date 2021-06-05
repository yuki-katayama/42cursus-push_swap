#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include "../libft/libft.h"
#define ERROR 1
#define WRITE 1
#define EXIT 0
#define SUCCESS 0

t_list	*ft_lstnew_ps(int content);
void	ft_lstadd_back_ps(t_list **lst, t_list *new);
t_list	*ft_lstlast_ps(t_list *lst);
int		ft_lstsize_ps(t_list *stack);
void	ft_rr(t_list **stack, char *str);
void	ft_r(t_list **stack, char *str);
void	ft_s(t_list **stack_a, char *str);
void	ft_s_s(t_list **stack_a, t_list **stack_b, char *str);
void	ft_p(t_list **stack_a, t_list **stack_b, char *str);

//check
int		ft_check_arg(int size, char **argv, t_list **stack_a, int **nums);

//ft_sort_two
void 	ft_sort_two(t_list **stack, char *str);

//ft_sort_three
void	ft_sort_three_a(t_list **stack_a);
void	ft_sort_three_b(t_list **stack_b);
void 	ft_sort_three(t_list **stack_a, t_list **stack_b);
void	ft_sort_three_over(t_list **stack_a, t_list **stack_b);


//ft_sort_four
void	ft_sort_four_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_four_b(t_list **stack_a, t_list **stack_b);
void 	ft_sort_four(t_list **stack_a, t_list **stack_b, int size);

//ft_sort_five
void	ft_sort_five_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_five_b(t_list **stack_a, t_list **stack_b);

//ft_sort_six
void	ft_sort_six(t_list **stack_a, t_list **stack_b);

//sort_under_five
void	ft_sort_under_five_b(t_list **a, t_list **b, int b_size);
void	ft_sort_under_five_a(t_list **stack_a, t_list **stack_b, int size);

//sort_over_five
int ft_sort_over_five(t_list **stack_a, t_list **stack_b, int size, int first);
int ft_proceed_if_smallest_a(t_list **stack_a, int size);
int ft_proceed_if_smallest(t_list **stack_a, t_list **stack_b, int size);
void	ft_over_five_repeat_in(t_list **stack_a, t_list **stack_b, int *sizes_a, int size_b);
void	ft_final(t_list **a, t_list **b, int *a_sizes, int remain_size);

//utils
int64_t ft_get_smallest(t_list **stack, int size);
int64_t ft_get_biggest(t_list **stack, int n);
void	ft_push(t_list **a, t_list **b, int size, char *str);
void	ft_push_rotate(t_list **a, t_list **b);
void	ft_last_push_rotate(t_list **stack_a, t_list **stack_b, int size_a, int size_b);
int		ft_get_half_size(int size);
int		ft_push_b_check_small(t_list **stack_a, t_list **stack_b, int size, int count);
void	ft_rotate(t_list **stack, int size, char *str);

//crear
void	clear_stack_nums(t_list *stack_a, int *nums);

//start
void 	ft_start_push_swap(t_list **stack_a, int size);

//median
int		ft_get_median(t_list *stack_a, int n, int minus);
// int		ft_get_m_median(t_list *stack_a, int n);


#endif