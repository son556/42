/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:11:09 by chanson           #+#    #+#             */
/*   Updated: 2023/01/19 20:41:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_BONUS_H
# define PIPE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "get_next_line.h"

# define FAIL		0
# define SUCCESS	1
# define READ		0
# define WRITE		1

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_addr;
	int		**pipe_fd;
	int		infile;
	int		outfile;
	char	**argvv;
	int		res;
	int		argc;
}			t_cmd;

//utils_bonus && utils
char	**ft_split(char *str, char c);
char	**ft_split_2(char *str);
char	*ft_strcpy(char	*str);
char	*ft_strcjoin(char *str1, char c);
char	*str_find(char **strs, char *find);
int		ft_strlen(char	*str);
char	*ft_strjoin(char *str1, char *str2);
//utils_bonus
int		str_cmp(char *str, char *cmp);
char	*str_cp_limit(char *str, int idx);
void	set_cmd(t_cmd *cmd);
void	free_cmd(t_cmd *cmd);
char	*str_copy(char *str);

//here_doc
void	here_doc(t_cmd *cmd, char *limit);

//parse_bonus
void	cmd_parse(t_cmd *cmd, char *argv, char **envp);

//pipe_bonus
void	start_fork(t_cmd *cmd, char **envp, int idx);
void	start_fork_first(t_cmd *cmd, char **envp, int idx);
void	start_fork_end(t_cmd *cmd, char **envp, int idx);
void	make_pipe(t_cmd *cmd, int n);

//error_bonus
void	str_put_error(char *str, t_cmd *cmd);
int		valid_check(t_cmd *cmd, char *argv, char **envp);

//init_bonus
char	*cmd_init_0(t_cmd *cmd, int i);

//temp
void	display_arr(char **str);
#endif
