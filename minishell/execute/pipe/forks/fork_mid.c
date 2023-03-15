/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:45:28 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 20:24:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	fork_in(t_tree *tree, int idx)
{
	close(tree->pipe_fd[idx][WRITE]);
	if (tree->infile != 0)
	{
		close(tree->pipe_fd[idx][READ]);
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error4\n");
	}
	else
	{
		if (dup2(tree->pipe_fd[idx][READ], STDIN_FILENO) == -1)
			ft_error("dup2 error5\n");
		close(tree->pipe_fd[idx][READ]);
	}
	close(tree->pipe_fd[idx + 1][READ]);
}

static void	close_pipe_not_use(t_tree *tree, int index)
{
	int	i;

	i = 0;
	while (i < tree->pipe_cnt)
	{
		if (i == index || i == index -1)
			i++;
		else
		{
			close(tree->pipe_fd[i][READ]);
			close(tree->pipe_fd[i][WRITE]);
			i++;
		}
	}
}

static void	infile_outfile_check(t_tree *tree, int index)
{
	if (tree->outfile != 0)
	{
		close(tree->pipe_fd[index][WRITE]);
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error6\n");
		close(tree->outfile);
	}
	else
	{
		if (dup2(tree->pipe_fd[index][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error7\n");
		close(tree->pipe_fd[index][WRITE]);
	}
}

static void	get_file_discript(t_tree *tree, char **cmd)
{
	tree->infile = get_ird(cmd);
	if (tree->infile == -1)
		return ;
	tree->outfile = get_ord(cmd);
}

void	fork_mid(t_tree *tree, int index, char **cmd)
{
	int	builtin_num;

	get_file_discript(tree, cmd);
	close_pipe_not_use(tree, index);
	fork_in(tree, index - 1);
	infile_outfile_check(tree, index);
	builtin_num = builtin_pipe(tree);
	if (builtin_num != 1)
		exit(builtin_num);
	if (builtin_num == 1)
	{
		if (tree->cmd.cmd_head == NULL)
			prt_err_2(tree->cmd.cmd_arr[0], ": cmd not found");
		if (execve(tree->cmd.cmd_head, tree->cmd.cmd_arr, tree->envp_val) == -1)
			prt_err_2(tree->cmd.cmd_arr[0], ": cmd not found");
	}
}
