#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

long long int	ft_atoi(const char *str);
int				ft_malloc_p(void **p, size_t len);
int				ft_malloc_pp(void ***p, size_t len);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_swap(int *a, int *b);
void			*ft_free_char(char **word, int index);
void			ft_free_int(int **ptr);
void			ft_quick_sort(int *nums, int left, int right);
char			**ft_split(char const *s, char c);

//print用
void ft_putnbr_fd(int num, int fd);
// t_list			*ft_lstnew(int content);
// t_list			*ft_lstlast(t_list *lst);
// void			ft_lstiter(t_list *lst);
// void			ft_lstdelone(t_list *lst);
// void			ft_lstclear(t_list **lst);
// void			ft_lstadd_front(t_list **lst, t_list *new);
// void			ft_lstadd_back(t_list **lst, t_list *new);
// void	*ft_memset(void *b, int c, size_t len);
// void	ft_bzero(void *s, size_t n);

#endif
