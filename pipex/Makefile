NAME = pipex

SRCS = ./error/str_put_error.c ./error/valid_check.c \
		./init/cmd_init_0.c ./init/cmd_init_1.c ./init/set_cmd.c \
		./parse/cmd_parse.c \
		./pipe/start_fork.c \
		./utils/ft_split_2.c ./utils/ft_split.c \
		./utils/ft_strcjoin.c ./utils/ft_strcpy.c ./utils/ft_strjoin.c \
		./utils/ft_strlen.c ./utils/str_find.c ./utils/str_in_str.c \
		./utils/display_arr.c \
		pipe.c

SRCS_B = ./bonus/utils_bonus/ft_split_2_bonus.c ./bonus/utils_bonus/ft_split_bonus.c \
		./bonus/utils_bonus/ft_strjoin_bonus.c ./bonus/utils_bonus/ft_strlen_bonus.c \
		./bonus/utils_bonus/set_cmd_bonus.c ./bonus/utils_bonus/str_cmp_bonus.c \
		./bonus/utils_bonus/str_cp_bonus.c ./bonus/utils_bonus/str_find_bonus.c \
		./bonus/utils_bonus/ft_strcjoin_bonus.c ./bonus/utils_bonus/ft_strcpy_bonus.c \
		./bonus/utils_bonus/free_cmd_bonus.c \
		./bonus/utils_bonus/str_copy_bonus.c \
		./bonus/pipe_bonus/start_fork_bonus.c \
		./bonus/pipe_bonus/start_fork_first_bonus.c \
		./bonus/pipe_bonus/start_fork_end_bonus.c \
		./bonus/pipe_bonus/make_pipe_bonus.c \
		./bonus/parse_bonus/cmd_parse_bonus.c \
		./bonus/init_bonus/init_bonus.c \
		./bonus/error_bonus/str_put_err_bonus.c ./bonus/error_bonus/valid_check_bonus.c \
		./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \
		./bonus/here_doc/here_doc.c pipe_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_B:.c=.o)

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra

ifdef BONUS
	OBJS_ALL = $(OBJS_BONUS)
else
	OBJS_ALL = $(OBJS)
endif

all:	$(NAME)

$(NAME):	$(OBJS_ALL)
			$(CC) $(CFLAGS) $(OBJS_ALL) -o $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(NAME)
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean

re:			fclean all

bonus:
	make BONUS=1 all

.PHONY:		all clean fclean re bonus