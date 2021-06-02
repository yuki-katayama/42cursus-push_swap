NAME	=	libft.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./libft

SRCDIR	=	./

SRCNAME	=	ft_atoi.c \
			ft_malloc_p.c \
			ft_malloc_pp.c \
			ft_isdigit.c \
			ft_malloc_p.c \
			ft_split.c \
			ft_free_int.c \
			ft_free_char.c \
			ft_strncmp.c \
			ft_swap.c \
			ft_quick_sort.c

SRCS	=	$(addprefix $(SRCDIR), $(SRCNAME))

OBJS	=	$(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar	rcs	$(NAME)	$(OBJS)

all:		$(NAME)


clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
