/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:43:40 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:43:41 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

int				ft_malloc_p(void **p, size_t len);
int				ft_malloc_pp(void ***p, size_t len);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_swap(int *a, int *b);
void			*ft_free_char(char **word, int index);
void			ft_free_int(int **ptr);
void			ft_quick_sort(int *nums, int left, int right);
char			**ft_split(char const *s, char c);
void			ft_putnbr_fd(int num, int fd);

#endif
