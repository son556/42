NAME = push_swap

SRCS = ./push_swap_algorithm/push_swap_algorithm.c ./push_swap_algorithm/push_swap_algorithm_2.c \
		./push_swap_algorithm/push_swap_algorithm_3.c ./push_swap_algorithm/push_swap_algorithm_4.c \
		./push_swap_algorithm/push_swap_algorithm_5.c ./push_swap_algorithm/push_swap_algorithm_6.c \
		./push_swap_algorithm/push_swap_algorithm_7.c ./push_swap_command/push_swap_command.c \
		./push_swap_command/push_swap_command_2.c ./push_swap_command/push_swap_command_3.c \
		./push_swap_deque/push_swap_deque.c ./push_swap_deque/push_swap_deque_2.c \
		./push_swap_deque/push_swap_deque_3.c \
		./push_swap_util/push_swap_util.c ./push_swap_util/push_swap_util_2.c push_swap.c

LIBFT_DIR = ./libftprintf2/

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT_DIR)
			$(CC) $(CFLAGS) $(SRCS) -o $@ ./libftprintf2/libftprintf.a

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re