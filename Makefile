NAME	=	push_swap

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCDIR  = ./srcs/

SRCS    = $(addprefix $(SRCDIR), $(SRCNAME))

VALGRIND = valgrind

VALFLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666

SRCNAME	=	push_swap \
			prepare \
			error_check \
			sort_two \
			sort_three \
			sort_four \
			sort_five \
			sort_six \
			sort_under_five \
			sort_over_five \
			utils \
			clear \
			start \
			median \
			ft_lstadd_back_ps \
			ft_lstlast_ps \
			ft_lstnew_ps \
			ft_lstsize_ps \
			ft_s \
			ft_r \
			ft_rr \
			ft_p

# BSRCNAME =	render_map \
			draw

SRCS	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME)))

# BSRCS	=	$(addsuffix _bonus.c, $(addprefix bonus/, $(SRCNAME) $(BSRCNAME)))

OBJS	=	$(SRCS:.c=.o)

# BOBJS	=	$(BSRCS:.c=.o)

.PHONY: all
all		:	$(NAME)

$(NAME) :	${OBJS}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} libft.a $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: san
san		:	${OBJS}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} -g -fsanitize=address libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: val
val		:	$(MLX) ${OBJS}
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) -g ${OBJS} libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			$(VALGRIND) $(VALFLAGS) ./push_swap

.PHONY: clean
clean	:
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft
			@echo "\033[0m"

.PHONY: fclean
fclean	:	clean
			@echo "\033[0;33mRemoving executable..."
			$(MAKE) fclean -C ./libft
			$(RM) $(NAME) libft.a
			@echo "\033[0m"

.PHONY: re
re		:	fclean all

.PHONY: test
test	:
			./push_swap 1 3 5 2 4 8 6

# .PHONY: bonus
# bonus:	fclean $(MLX) $(BOBJS)
# 		@echo "\n\033[0;32mCompiling..."
# 		$(MAKE) -C ./libft
# 		$(MAKE) -C ./minilibx-linux
# 		cp ./minilibx-linux/libmlx_Linux.a .
# 		cp ./libft/libft.a .
# 		$(CC) ${BOBJS} libmlx_Linux.a libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
# 		@echo "Complete\033[0m"