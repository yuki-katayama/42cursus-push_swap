# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:43:41 by kyuki             #+#    #+#              #
#    Updated: 2021/07/05 12:43:42 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC	= gcc

CFLAGS	= -Wall	-Wextra	-Werror

RM		=	rm -f

INCDIR	=	./libft

SRCDIR	=	./

SRCNAME	=	ft_malloc_p.c \
			ft_malloc_pp.c \
			ft_isdigit.c \
			ft_malloc_p.c \
			ft_split.c \
			ft_free_int.c \
			ft_free_char.c \
			ft_strncmp.c \
			ft_swap.c \
			ft_quick_sort.c \
			ft_putnbr_fd.c

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
