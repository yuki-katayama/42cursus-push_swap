NAME	=	push_swap

MV		= -mv
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
			sort_over_five_utils \
			sort_over_five_rec \
			utils \
			push_rotate \
			proceed_if \
			clear \
			start \
			median \
			split_median \
			ft_lstadd_back_ps \
			ft_lstlast_ps \
			ft_lstnew_ps \
			ft_lstsize_ps \
			ft_s \
			ft_r \
			ft_rr \
			ft_p

ifeq ($(shell uname),Linux)
	CHECKERURL = https://projects.intra.42.fr/uploads/document/document/3597/checker_linux -O
	CHECKERNAME = checker_linux
else
	CHECKERURL = https://projects.intra.42.fr/uploads/document/document/3596/checker_Mac -O
	CHECKERNAME = checker_Mac
endif

SRCS	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME)))

OBJS	=	$(SRCS:.c=.o)




.PHONY: all
all	:	color $(NAME) ## Run compile

color :
		@echo "\n\033[0;32mpush_swap Compiling..."

$(NAME) :	$(OBJS)
			curl -O $(CHECKERURL)
			$(MV) $(CHECKERNAME) checker
			chmod a+x checker
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) ${OBJS} libft.a $(CFLAGS) -g -o ${NAME}
			@echo "push_swap Complete\033[0m"

.PHONY: san
san	:	color ${OBJS} ## Run sanitize
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) -g ${OBJS} -fsanitize=address libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

.PHONY: val
val	:	color ${OBJS} ## Run valgrind
			$(MAKE) -C ./libft
			cp ./libft/libft.a .
			$(CC) -g ${OBJS} libft.a $(CFLAGS) $(LXFLAGS) -o ${NAME}
			$(VALGRIND) $(VALFLAGS) ./push_swap "-5 4 2 3 10 9 8 11 15"

.PHONY: clean
clean	:	## Remove object
			@echo "\033[0;33mCleaning..."
			$(RM) $(OBJS)
			$(MAKE) clean -C ./libft
			@echo "\033[0m"

.PHONY: fclean
fclean	:	clean ## Remove object and static
			@echo "\033[0;35mRemoving executable..."
			$(MAKE) fclean -C ./libft
			$(RM) -R $(NAME) libft.a checker push_swap_tester
			@echo "\033[0m"

.PHONY: re
re	:	fclean all ## Retry cmpiles

.PHONY: test
test	:	## Display test script
			@echo "\033[0;31mPlease delete single-quotation\033[0m"
			@echo "ARG='$$'(jot -r -s \" \" 100 -2147483648 2147483647); ./push_swap '$$'ARG | ./checker '$$'ARG"

tester	:	## Download tester
			git clone git@github.com:nafuka11/push_swap_tester.git

.PHONY: help
help	: ## Display this help
	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
