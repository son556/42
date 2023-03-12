/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:57:16 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 20:24:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	fork_in(t_tree *tree, int idx)
{
	if (tree->infile != 0)
	{
		close(tree->pipe_fd[idx][READ]);
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error8\n");
	}
	else
	{
		if (dup2(tree->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			ft_error("dup2 error9\n");
		close(tree->pipe_fd[idx][READ]);
	}
}

static void	last_outfile_check(t_tree *tree)
{
	if (tree->outfile != 0)
	{
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error10\n");
	}
}

static void	get_file_discript(t_tree *tree, char **cmd)
{
	tree->infile = get_ird(cmd);
	if (tree->infile == -1)
		return ;
	tree->outfile = get_ord(cmd);
}

void	fork_last(t_tree *tree, char **cmd)
{
	int	builtin_num;
	int	i;

	get_file_discript(tree, cmd);
	i = 0;
	while (i < tree->pipe_cnt - 1)
	{
		close(tree->pipe_fd[i][READ]);
		close(tree->pipe_fd[i][WRITE]);
		i++;
	}
	fork_in(tree, tree->pipe_cnt - 1);
	close(tree->pipe_fd[tree->pipe_cnt - 1][WRITE]);
	last_outfile_check(tree);
	builtin_num = builtin_pipe(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	if (builtin_num == 1)
	{
		if (tree->cmd.cmd_head == NULL)
			prt_err_2(tree->cmd.cmd_arr[0], ": cmd not found");
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			ft_error("cmd option error child\n");
	}
}
