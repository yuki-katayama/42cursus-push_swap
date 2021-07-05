/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:44:09 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:44:14 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include "../libft/libft.h"
# define ERROR 1
# define EXIT 0
# define SUCCESS 0

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
void	ft_sort_two(t_list **stack, char *str);

//ft_sort_three
void	ft_sort_three_a(t_list **stack_a);
void	ft_sort_three_b(t_list **stack_b);
void	ft_sort_three(t_list **stack_a, t_list **stack_b);
void	ft_sort_three_over(t_list **stack_a, t_list **stack_b);

//ft_sort_four
void	ft_sort_four_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_four_b(t_list **stack_a, t_list **stack_b);
void	ft_sort_four(t_list **stack_a, t_list **stack_b, int size);

//ft_sort_five
void	ft_sort_five_a(t_list **stack_a, t_list **stack_b);
void	ft_sort_five_b(t_list **stack_a, t_list **stack_b);

//ft_sort_six
void	ft_sort_six(t_list **stack_a, t_list **stack_b);

//sort_under_five
void	ft_sort_under_five_b(t_list **a, t_list **b, int b_size);
void	ft_sort_under_five_a(t_list **stack_a, t_list **stack_b, int size);

//sort_over_five
int		ft_sort_over_five(t_list **stack_a, t_list **stack_b, \
							int size, int first);
int		ft_proceed_if_smallest_a(t_list **stack_a, int size);
int		ft_proceed_if_smallest(t_list **stack_a, t_list **stack_b, int size);

//sort_over_five_rec
void	ft_over_five_repeat_in(t_list **stack_a, t_list **stack_b, \
								int *sizes_a, int size_b);
void	ft_over_five_last(t_list **stack_a, t_list **stack_b, \
							int *a_sizes, int remain_size);

//sort_over_five_utils
int		ft_count_five_size(int size);
int		ft_over_five(t_list **stack_a, t_list **stack_b, int size);
void	ft_define_size2(int size, int *sizes_a, int *size_b, int *size_remain);
int		ft_define_size(int size, int *sizes_a, int *size_b, int i);

//utils
int64_t	ft_get_smallest(t_list **stack, int size);
int64_t	ft_get_biggest(t_list **stack, int n);
int		ft_get_half_size(int size);
int		ft_push_b_check_small(t_list **stack_a, t_list **stack_b, \
								int size, int count);

//push_rotate
void	ft_push(t_list **stack_a, t_list **stack_b, int size, char *str);
void	ft_push_rotate(t_list **stack_a, t_list **stack_b);
void	ft_last_push_rotate(t_list **stack_a, t_list **stack_b, \
								int size_a, int size_b);
void	ft_rotate(t_list **stack, int size, char *str);

//proceed_if
int		ft_proceed_if_smallest_a(t_list **stack_a, int size);
int		ft_proceed_if_smallest(t_list **stack_a, t_list **stack_b, int size);

//prepare
int		ft_prepare_nums(int size, char **argv, t_list **stack_a, int **nums);
int		ft_define_size_array(int ac, char ***argv, char **av, int *size);

//crear
void	ft_clear_stack_nums(t_list *stack_a, int *nums);
void	ft_clear_argv(int ac, char **argv);

//start
void	ft_start_push_swap(t_list **stack_a, int size);

//median
int		ft_get_median(t_list *stack_a, int n, int minus);

//split_median
int		ft_split_median_a(t_list **stack_a, t_list **stack_b, int size);
int		ft_split_median_b(t_list **stack_a, t_list **stack_b, \
							int size, int *proceed);
#endif