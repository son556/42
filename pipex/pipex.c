/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:17:49 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 20:04:37 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipe.h"

static int	open_file(t_cmd *cmd, char *infile, char *outfile)
{
	cmd->infile = open(infile, O_RDONLY);
	if (cmd->infile < 0)
		perror("infile not found");
	cmd->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile < 0)
		perror("outfile not found");
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;

	set_cmd(&cmd);
	if (argc == 5)
	{
		open_file(&cmd, argv[1], argv[4]);
		valid_check(&cmd, argv[2], envp, 0);
		valid_check(&cmd, argv[3], envp, 1);
		start_fork(&cmd, envp);
	}
	else
	{
		write(2, "not valid argv cnt\n", 19);
		exit(EXIT_FAILURE);
	}
	return (0);
}
