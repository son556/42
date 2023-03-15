/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_first.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:43:24 by chanson           #+#    #+#             */
/*   Updated: 2023/03/13 18:40:54 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/test.h"

static void	_fork_in(t_tree *tree)
{
	if (tree->infile != 0)
	{
		if (dup2(tree->infile, STDIN_FILENO) == -1)
			ft_error("dup2 error1\n");
		close(tree->infile);
	}
	if (tree->outfile != 0)
	{
		close(tree->pipe_fd[0][WRITE]);
		if (dup2(tree->outfile, STDOUT_FILENO) == -1)
			ft_error("dup2 error2\n");
		close(tree->outfile);
	}
	else
	{
		if (dup2(tree->pipe_fd[0][WRITE], STDOUT_FILENO) == -1)
			ft_error("dup2 error3\n");
		close(tree->pipe_fd[0][WRITE]);
	}
}

static void	get_file_discript(t_tree *tree, char **cmd)
{
	tree->infile = get_ird(cmd);
	if (tree->infile == -1)
		return ;
	tree->outfile = get_ord(cmd);
}

void	fork_first(t_tree *tree, char **cmd)
{
	int	builtin_num;
	int	i;

	get_file_discript(tree, cmd);
	i = 1;
	while (i < tree->pipe_cnt)
	{
		close(tree->pipe_fd[i][READ]);
		close(tree->pipe_fd[i][WRITE]);
		i++;
	}
	close(tree->pipe_fd[0][READ]);
	_fork_in(tree);
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
