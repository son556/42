/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:49:28 by chanson           #+#    #+#             */
/*   Updated: 2023/01/18 21:08:24 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	cmd_argv_parse(t_cmd *cmd, char *argv)
{
	cmd->argvv = ft_split_2(argv);
}

static int	check_access(t_cmd *cmd, char *temp)
{
	if (access(temp, X_OK) == 0)
	{
		cmd->cmd_addr = temp;
		return (1);
	}
	return (0);
}

void	cmd_parse(t_cmd *cmd, char *argv, char **envp)
{
	int		i;
	char	*temp;

	temp = str_find(envp, "PATH");
	if (cmd->cmd == NULL)
		cmd->cmd = ft_split(temp, ':');
	free(temp);
	cmd_argv_parse(cmd, argv);
	if (access(cmd->argvv[0], X_OK) == 0)
	{
		cmd->cmd_addr = str_copy(cmd->argvv[0]);
		return ;
	}
	i = -1;
	while (cmd->cmd[++i])
	{
		temp = cmd_init_0(cmd, i);
		if (check_access(cmd, temp))
			return ;
		free(temp);
	}
}
