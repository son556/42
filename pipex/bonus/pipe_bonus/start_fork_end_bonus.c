/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fork_end_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:08:09 by chanson           #+#    #+#             */
/*   Updated: 2023/01/20 15:42:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	_strat_parent_process(t_cmd *cmd, int idx)
{
	char	*line;

	close(cmd->pipe_fd[idx][WRITE]);
	close(cmd->pipe_fd[idx - 1][READ]);
	if (dup2(cmd->pipe_fd[idx][READ], STDIN_FILENO) == -1)
		str_put_error("dup2 error parent end fd2", cmd);
	if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
		str_put_error("dup2 error parent end fd", cmd);
	line = get_next_line(cmd->pipe_fd[idx][READ]);
	while (line)
	{
		write(cmd->outfile, line, ft_strlen(line));
		free(line);
		line = get_next_line(cmd->pipe_fd[idx][READ]);
	}
	free(line);
	close(cmd->outfile);
}

void	start_fork_end(t_cmd *cmd, char **envp, int idx)
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
			str_put_error("dup2 error child end fd2", cmd);
		if (execve(cmd->cmd_addr, cmd->argvv, envp) == -1)
			str_put_error("cmd option error child", cmd);
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		_strat_parent_process(cmd, idx);
	}
}
