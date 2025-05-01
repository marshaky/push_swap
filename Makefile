NAME			= push_swap

LIBFT 			= libft/libft.a

SRCS 			=	atoi_long.c butterfly.c check_args.c create_stack.c \
					push_swap_stack.c  push_swap.c  pw_utils.c \
					quicksort.c rotate_reverse_stack.c sort_for_small.c \

OBJS 			=  ${SRCS:.c=.o}

CC 				= cc
RM 				= rm -rf
CFLAGS			= -Wall -Wextra -Werror

all:			$(NAME)

$(NAME): 		$(OBJS)
					$(MAKE) -C ./libft
					$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)


clean:
				$(MAKE) clean -C ./libft
				${RM} $(OBJS)

fclean:			clean
					$(MAKE) fclean -C ./libft
					${RM} $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re