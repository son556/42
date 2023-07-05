NAME = minishell

SRCS_NAME =  ./test \
		./utils/ft_split \
		./utils/ft_split_2 \
		./utils/ft_split_3 \
		./utils/ft_free_str \
		./utils/ft_strcjoin \
		./utils/ft_strsjoin \
		./utils/ft_strcpy \
		./utils/ft_strscmp \
		./utils/ft_strstr \
		./utils/ft_strtrim \
		./utils/ft_str_change \
		./utils/ft_strlen \
		./utils/ft_itoa \
		./utils/ft_str_find_c \
		./utils/ft_strcpy_index \
		./utils/ft_strfind \
		./utils/ft_strinsert \
		./utils/fr_strdel_one \
		./utils/ft_atoi \
		./utils/ft_error \
		./utils/ft_split_char \
		./utils/ft_strncmp \
		./utils/ft_isalnum \
		./utils/ft_isalpha \
		./utils/ft_str_size \
		./utils/ft_strchr \
		./utils/ft_strrchr \
		./utils/str_find \
		./utils/ft_strjoin \
		./utils/check_remove_quote \
		./utils/ft_strstr_no_free \
		./utils/ft_free_tree \
		./utils/ft_strsjoin_2 \
		./utils/ft_erase_null \
		./parsing/syntax_check/syntax_check \
		./parsing/syntax_check/check_pattern \
		./parsing/syntax_check/check_str_valid \
		./parsing/syntax_check/syntax_check_err \
		./parsing/tree/make_tree \
		./parsing/tree/decide_type \
		./parsing/tree/make_list \
		./parsing/tree/add_node_to_tree \
		./execute/pipe/pipe \
		./execute/pipe/execute_pipe \
		./execute/pipe/execute_no_pipe \
		./execute/pipe/cmd_check \
		./execute/pipe/get_cmd_redir \
		./execute/pipe/get_cmd_redir_ord \
		./execute/pipe/forks/fork_first \
		./execute/pipe/forks/fork_mid \
		./execute/pipe/forks/fork_last \
		./execute/heredoc/heredoc \
		./execute/heredoc/heredoc_cnt \
		./execute/heredoc/heredoc_env \
		./execute/heredoc/mini_heredoc \
		./execute/heredoc/heredoc_sum \
		./execute/heredoc/unlink_heredoc \
		./signal/handler \
		./signal/do_signal_handle \
		./builtin/builtin_cd_1 \
		./builtin/builtin_cd_2 \
		./builtin/builtin_echo \
		./builtin/builtin_env_1 \
		./builtin/builtin_env_2 \
		./builtin/builtin_error \
		./builtin/builtin_exit \
		./builtin/builtin_export_1 \
		./builtin/builtin_export_2 \
		./builtin/builtin_main \
		./builtin/builtin_pwd \
		./builtin/builtin_unset \
		./builtin/change_env_question \
		./builtin/parent_unset_export \
		./builtin/builtin_echo_quote \
		./builtin/builtin_echo_split \
		./builtin/builtin_echo_option \
		./init_heredoc_and_pipe \
		./set_tree \
		./start_minishell \
		./get_next_line/get_next_line \
		./get_next_line/get_next_line_utils \
		./builtin/builtin_export_split \
		./builtin/builtin_split \
		./builtin/builtin_getcmd \
		./builtin/builtin_export_args \
		./builtin/builtin_export_valid \
		./utils/display \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -L/Users/chanson/.brew/opt/readline/lib -lreadline -lncurses

CPPFLAGS = -I/Users/chanson/.brew/opt/readline/include

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(LDFLAGS) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
			$(CC) $(FLAGS) $(CPPFLAGS) -c $< -o $@

clean:		
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all re fclean