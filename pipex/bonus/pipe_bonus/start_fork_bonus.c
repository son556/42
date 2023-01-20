/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fork_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:08:14 by chanson           #+#    #+#             */
/*   Updated: 2023/01/20 15:42:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

void	start_fork(t_cmd *cmd, char **envp, int idx)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		str_put_error("fork error", cmd);
	if (pid == 0)
	{
		close(cmd->pipe_fd[idx][READ]);
		if (dup2(cmd->pipe_fd[idx][WRITE], STDOUT_FILENO) == -1)
			str_put_error("dup2 error child fork fd2", cmd);
		if (execve(cmd->cmd_addr, cmd->argvv, envp) == -1)
			str_put_error("cmd option error child", cmd);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		if (dup2(cmd->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			str_put_error("dup2 error parent first", cmd);
		close(cmd->pipe_fd[idx][READ]);
		close(cmd->pipe_fd[idx][WRITE]);
	}
}
