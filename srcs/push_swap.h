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
int	ft_check_arg(int size, char **argv, t_list **stack_a, int **nums);

//sort_two_ore_three
void 	ft_sort_two(t_list **stack, char *str);
void	ft_sort_three_a(t_list **stack_a);
void	ft_sort_three_b(t_list **stack_b);

//sort_four
void	ft_sort_four(t_list **stack_a, t_list **stack_b);

//sort_five
void	ft_sort_five(t_list **stack_a, t_list **stack_b);

//sort_six
void	ft_sort_six(t_list **stack_a, t_list **stack_b);

//utils
int64_t ft_get_smallest(t_list **stack, int n);
int64_t ft_get_biggest(t_list **stack, int n);
void	ft_push(t_list **a, t_list **b, int size);
void	ft_push_rotate(t_list **a, t_list **b);

//crear
void	clear_stack_nums(t_list *stack_a, int *nums);

//start
void ft_start_push_swap(t_list **stack_a, int size);

//median
int	ft_get_median(t_list *stack_a, int n, int minus);


#endif