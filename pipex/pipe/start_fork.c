/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:41:42 by chanson           #+#    #+#             */
/*   Updated: 2023/05/28 17:07:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

static void	_strat_parent_process(t_cmd *cmd, char **envp)
{
	close(cmd->pipe_fd[1]);
	if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		str_put_error("dup2 error parent", cmd);
	if (dup2(cmd->pipe_fd[0], STDIN_FILENO) == -1)
		str_put_error("dup2 error parent", cmd);
	execve(cmd->cmd_addr[1], cmd->argvv2, envp);
	str_put_error("cmd option error parent", cmd);
}

void	start_fork(t_cmd *cmd, char **envp)
{
	pid_t	pid;
	int		status;

	if (pipe(cmd->pipe_fd) == -1)
		str_put_error("pipe error", cmd);
	pid = fork();
	if (pid < 0)
		str_put_error("fork error", cmd);
	if (pid == 0)
	{
		close(cmd->pipe_fd[0]);
		if (dup2(cmd->infile, STDIN_FILENO) == -1)
			str_put_error("dup2 error child", cmd);
		if (dup2(cmd->pipe_fd[1], STDOUT_FILENO) == -1)
			str_put_error("dup2 error child", cmd);
		if (execve(cmd->cmd_addr[0], cmd->argvv, envp) == -1)
			str_put_error("cmd option error child", cmd);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		_strat_parent_process(cmd, envp);
	}
}
