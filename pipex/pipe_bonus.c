/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:46:15 by chanson           #+#    #+#             */
/*   Updated: 2023/01/19 21:34:23 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipe_bonus.h"

static int	open_file(t_cmd *cmd, char *infile, char *outfile)
{
	cmd->infile = open(infile, O_RDONLY);
	if (cmd->infile < 0)
		perror("infile not found");
	cmd->outfile = open(outfile, O_WRONLY | O_APPEND, 0644);
	if (cmd->outfile < 0)
		cmd->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile < 0)
		perror("outfile not found");
	return (1);
}

static void	open_outfile(t_cmd *cmd, char *outfile)
{
	cmd->outfile = open(outfile, O_WRONLY | O_APPEND, 0644);
	if (cmd->outfile < 0)
		cmd->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile < 0)
		perror("outfile not found");
}

static void	_start_process(t_cmd *cmd, char **argv, char **envp, int idx)
{
	int	i;
	int	j;

	i = idx;
	j = 0;
	while (i < cmd->argc - 1)
	{
		valid_check(cmd, argv[i], envp);
		if (i == idx)
			start_fork_first(cmd, envp, j);
		else if (i == cmd->argc - 2)
			start_fork_end(cmd, envp, j);
		else
			start_fork(cmd, envp, j);
		free_cmd(cmd);
		i++;
		j++;
	}
	if (idx == 3)
		if (unlink(argv[1]) == -1)
			str_put_error("unlink error", cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		i;

	set_cmd(&cmd);
	cmd.argc = argc;
	if (argc >= 5)
	{
		if (str_cmp(argv[1], "here_doc"))
		{
			here_doc(&cmd, argv[2]);
			open_outfile(&cmd, argv[argc - 1]);
			make_pipe(&cmd, 1);
			i = 3;
		}
		else
		{
			open_file(&cmd, argv[1], argv[argc - 1]);
			make_pipe(&cmd, 0);
			i = 2;
		}
		_start_process(&cmd, argv, envp, i);
	}
	else
		write(2, "not valid argv cnt\n", 19);
}

void	display_arr(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (1)
	{
		printf("%s\n", str[i]);
		if (str[i] == NULL)
			break ;
		i++;
	}
}
