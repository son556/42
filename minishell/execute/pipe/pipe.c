/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:06:18 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 18:34:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

int	count_pipe(char **temp)
{
	int		cnt;
	int		i;

	i = -1;
	cnt = 0;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "|") == TRUE)
			cnt++;
	}
	return (cnt);
}

void	setting_pipe(t_tree *tree)
{
	int	i;

	tree->pipe_fd = (int **)malloc(sizeof(int *) * tree->pipe_cnt);
	if (tree->pipe_fd == NULL)
		ft_error("malloc error //pipe.c\n");
	i = -1;
	while (++i < tree->pipe_cnt)
	{
		tree->pipe_fd[i] = (int *)malloc(sizeof(int) * 2);
		if (tree->pipe_fd[i] == NULL)
			ft_error("malloc error //pipe.c\n");
	}
	tree->pid = (pid_t *)malloc(sizeof(pid_t) * (tree->pipe_cnt + 1));
	i = -1;
	while (++i < tree->pipe_cnt + 1)
		tree->pid[i] = -1;
	if (tree->pid == NULL)
		ft_error("malloc error //pipe.c\n");
	i = -1;
	while (++i < tree->pipe_cnt)
	{
		if (pipe(tree->pipe_fd[i]) == -1)
			ft_error("pipe create error //pipe.c\n");
	}
}

void	wait_pid(t_tree *tree)
{
	int		i;
	int		last_status;
	pid_t	pid;

	i = -1;
	while (++i < tree->pipe_cnt + 1)
	{
		pid = waitpid(0, &tree->child_status, 0);
		if (pid == tree->pid[tree->pipe_cnt])
			last_status = tree->child_status;
	}
	tree->child_status = last_status;
	tree = change_q_mark(tree, tree->child_status, 1);
}

void	close_pipe_all(t_tree *tree)
{
	int	i;

	i = 0;
	while (i < tree->pipe_cnt)
	{
		close(tree->pipe_fd[i][READ]);
		close(tree->pipe_fd[i][WRITE]);
		i++;
	}
}
