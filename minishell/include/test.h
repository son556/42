/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:59:58 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 20:21:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# define FALSE 0
# define TRUE 1
# define READ 0
# define WRITE 1
# define PARENT	4
# define CHILD	5
# define WAIT_CHILD 6
# define HEREDOC 7

# define PIPE 1
# define N_FILE 2

# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARRAOW 4348699
# define BACKSPACE 127
# define CTRL_D 4

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <dirent.h>
# include "../get_next_line/get_next_line.h"

enum e_token
{
	TK_STR,
	TK_IRD,
	TK_ORD,
	TK_HRD,
	TK_ARD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_LPT,
	TK_RPT,
	TK_INVALID,
	TK_EXPANDED_STR,
	TK_QUOTED_STR
};

typedef struct s_token
{
	char			*val;
	struct s_token	*left;
	struct s_token	*right;
	enum e_token	type;
}	t_token;

typedef struct s_list
{
	t_token	*first;
	t_token	*last;
}	t_list;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*prev;
	struct s_env_list	*next;
}	t_env;

typedef struct s_cmd
{
	char	*cmd_head;
	char	**cmd_arr;
	char	**envp_path;
}	t_cmd;

typedef struct s_cusor
{
	struct termios	org_term;
	struct termios	new_term;
	struct termios	child_term;
}	t_cursor;

typedef struct s_tree
{
	t_token		*top;
	t_token		*last;
	t_cursor	cursor;
	t_cmd		cmd;
	char		*origin;
	char		**pure;
	char		**export_temp;
	int			pipe_cnt;
	int			here_doc;
	int			mini_here_doc;
	int			here_doc_cnt;
	int			infile;
	int			outfile;
	int			child_status;
	int			heredoc_idx;
	int			**pipe_fd;
	int			exit_code;
	char		**here_documets;
	char		**envp_val;
	char		**history;
	char		**echo_export_arr;
	pid_t		*pid;
	t_env		*env_list;
	t_env		*export_list;
}	t_tree;

// utils
char	*ft_strcjoin(char *s, char c);
char	*ft_str_change(char *old, char *new);
char	*ft_strcpy_index(char *str, int start, int end);
char	*ft_strcpy(char *str);
char	*ft_strstr(char *str_origin, char *str_new);
char	*ft_strtrim_couple(char *str, char c1, char c2);
char	*ft_strtrim(char *str, char c);
char	*ft_strtrim_couple_check(char *str, char c1, char c2);
char	*ft_itoa(int num);
char	*ft_strfind(char **strs, char *find);
char	*ft_strinsert(char *str, char *insert, int start, int end);
char	*fr_strdel_one(char *str, int index);
char	*str_find(char **strs, char *find);
char	*ft_strstr_no_free(char *str_origin, char *str_new);
char	*ft_strjoin(char *str1, char *str2);
char	*fr_strdel_one(char *str, int index);
char	**ft_strsjoin(char **str1, char *str);
char	**ft_strsjoin_2(char **str1, char *str);
char	**ft_split(char *s);
char	**ft_split_char(char *str, char c);
char	**remove_quote(char **temp);
char	**ft_erase_null(char **cmd);
int		ft_split_and(char ***temp, char *str, int idx);
int		ft_split_par(char ***temp, char *str, int idx);
int		ft_strscmp(char *str1, char *str2);
int		ft_strlen(char *str);
int		ft_str_find_c(char *str, char c);
int		ft_atoi(const char *str);
int		ft_split_quote(char ***temp, char *str, int idx);
int		ft_split_redirection(char ***temp, char *str, int idx);
int		ft_split_pipe(char ***temp, char *str, int idx);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strrchr(char *s, int c);
int		ft_strchr(const char *s, int c);
int		str_size(char **str);
int		check_remove_quote(char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
void	ft_free_str(char **str);
void	ft_error(char *str);
void	ft_free_tree(t_tree *tree);

//parsing/syntax_check
int		syntax_check(char **temp);
int		check_pattern(char **temp, int *type_list, int idx);
int		check_str_valid(char *str);
int		syntax_err_check(char **temp);

//parsing/tree
t_tree	*init_tree(char **temp, t_tree *tree);
t_token	*add_node(t_list *list, t_tree *tree, int d, t_token **pre);
int		make_list(char **temp, t_list *list);
int		decide_type(char *str);

//execute/pipe
int		count_pipe(char **temp);
int		get_ird(char **temp);
int		get_ord(char **temp);
char	**cmd_get(char **temp);
void	setting_pipe(t_tree *tree);
void	wait_pid(t_tree *tree);
void	cmd_check(t_tree *tree, char **cmd);
void	fork_first(t_tree *tree, char **cmd);
void	fork_mid(t_tree *tree, int index, char **cmd);
void	fork_last(t_tree *tree, char **cmd);
void	execute_pipe(char **temp, t_tree *tree);
void	execute_no_pipe(char **temp, t_tree *tree);
void	close_pipe_all(t_tree *tree);
void	change_env_val(char **pure_cmd, t_tree *tree);
void	set_execute_cmd(t_tree *tree);
void	close_fd(int *cnt, int fd);

//execute/heredoc
void	cnt_heredoc(t_token *node, t_tree *tree);
void	execute_heredoc(t_token *node, t_tree *tree, char c);
void	*change_env(char **envp, char *temp);
void	mini_heredoc(t_token *node, t_tree *tree);
int		ft_heredoc(t_tree *tree, char *limit);
void	heredoc_sum(t_token *node, char ***temp);
void	sig_heredoc_ctrl_c(int signo);
void	unlink_heredoc(t_tree *tree);

// execute/builtin
int		do_cd(t_tree *info);
void	cd_home(t_env *env_list);
int		check_dir(char *cwd_buf);
int		change_dir(t_tree *info, char *cwd_buf);
char	*check_cd_argv(char *str, char *cwd_buf);
int		do_echo(t_tree *info);
char	*remove_quote_builtin(char *s);
void	print_else(char *s, t_env *env_list, int *i);
int		check_echo_option(char **temp, int *i, int *flag);
char	*builtin_getcmd(char **pure_cmd, char *s);
int		print_env_value(char *s, int start, t_env *env_list);
int		do_env(t_tree *info);
char	**env_to_envp(t_env *env_list);
char	**envp_copy(char **envp);
char	**builtin_split(char *str);
t_env	*add_env_list(t_env *env_list, char *key, char *value);
t_env	*make_env_list(char **envp);
t_env	*sort_export_list(t_env *export_list);
t_env	*make_export_list(char **envp);
char	*find_path(t_tree *info);
int		do_exit_pipe(t_tree *info);
int		do_exit_no_pipe(t_tree *info);
int		do_export(t_tree *info);
char	**export_split(char *str);
int		export_args(t_tree *info, char **cmd);
void	print_export(t_env *export_list);
int		valid_check(t_tree *info, char **str);
int		do_pwd(t_tree *info);
int		list_unset(char **cmd, t_env **env_list);
int		do_unset(t_tree *info);
void	relink_env_list(t_env *tmp);
int		builtin_no_pipe(t_tree *info);
int		builtin_pipe(t_tree *info);
int		print_error_1(char *str);
int		print_error_2(char *str1, char *str2);
int		print_error_3(char *str1, char *str2, char *str3);
void	prt_err_2(char *str1, char *str2);
t_tree	*change_q_mark(t_tree *tree, int value, int flag);
void	parent_unset_export(t_tree *info);
void	remove_quote_and_print(char *s, t_env *env_list);
char	**echo_split(char *str);
int		temp_check(char **str);
int		check_exist_key(t_tree *info, char **key, char **value);
void	find_key_value(t_tree *info, char *str, char **key, char **value);

//signal
void	on_off_catch_signals(int on_off);
void	do_signal_handle(int status);
void	signal_sigterm(char *str);
void	main_sigint(int signo);
void	set_terminal(t_tree *tree);
void	set_mode(t_tree *tree);
void	set_child_mode(t_tree *tree);

// utils->display.c
void	show_list(t_list	*list);
void	display_str(char **str);
void	display_tree(t_token *root, char c);
void	display_acc_str(char *str);
void	show_node_list(t_token *token);
void	display_list_envp(t_env *node);
void	display_tree_all(t_tree *tree);
void	reset_terminal(t_tree *tree);

// set_tree.c
t_tree	*tree_preset(char **envp);
t_tree	*tree_set_re(t_tree *tree);

// start_minishell.c
void	start_minishell(t_tree *tree);

// init_heredoc_and_pipe.c
void	_init_heredoc_and_pipe(t_tree *tree, char ***temp, char *str);

// display
void	show_list(t_list	*list);
void	show_node_list(t_token *token);
void	display_str(char **str);
void	display_tree(t_token *root, char c);
void	display_acc_str(char *str);
void	display_list_envp(t_env *node);
void	display_tree_all(t_tree *tree);
#endif