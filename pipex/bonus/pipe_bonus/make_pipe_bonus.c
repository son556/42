/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:31:56 by chanson           #+#    #+#             */
/*   Updated: 2023/01/19 16:43:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	make_pipe_here_doc(t_cmd *cmd)
{
	int	i;

	cmd->pipe_fd = (int **)malloc(sizeof(int *) * (cmd->argc - 4));
	i = 0;
	while (i < cmd->argc - 4)
	{
		cmd->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	i = 0;
	while (i < cmd->argc - 4)
	{
		if (pipe(cmd->pipe_fd[i]) == -1)
			str_put_error("pipe error", cmd);
		i++;
	}
}

void	make_pipe(t_cmd *cmd, int n)
{
	int	i;

	if (n == 0)
	{
		cmd->pipe_fd = (int **)malloc(sizeof(int *) * (cmd->argc - 3));
		i = 0;
		while (i < cmd->argc - 3)
		{
			cmd->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
			i++;
		}
		i = 0;
		while (i < cmd->argc - 3)
		{
			if (pipe(cmd->pipe_fd[i]) == -1)
				str_put_error("pipe error", cmd);
			i++;
		}
	}
	else
		make_pipe_here_doc(cmd);
}
