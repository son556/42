/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:18:37 by chanson           #+#    #+#             */
/*   Updated: 2023/01/13 19:12:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

# define FAIL		0
# define SUCCESS	1

typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_addr[2];
	int		pipe_fd[2];
	int		infile;
	int		outfile;
	char	**argvv;
	char	**argvv2;
	int		res;
}			t_cmd;

//utils
void	display_arr(char **str);
char	**ft_split(char *str, char c);
char	**ft_split_2(char *str);
char	*ft_strcpy(char	*str);
char	*ft_strcjoin(char *str1, char c);
char	*str_find(char **strs, char *find);
int		ft_strlen(char	*str);
char	*ft_strjoin(char *str1, char *str2);
int		str_in_str(char *str, char *check);

//init
void	set_cmd(t_cmd *cmd);
char	*cmd_init_0(t_cmd *cmd, int i);
char	*cmd_init_1(t_cmd *cmd, int i);

//error
void	str_put_error(char *str, t_cmd *cmd);
int		valid_check(t_cmd *cmd, char *argv, char **envp, int n);

//pipe
void	start_fork(t_cmd *cmd, char **envp);

//parse
void	cmd_parse(t_cmd *cmd, char *argv, char **envp, int n);

#endif