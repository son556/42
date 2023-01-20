/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:43:42 by chanson           #+#    #+#             */
/*   Updated: 2023/01/12 16:50:07 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

static void	cmd_argv_parse(t_cmd *cmd, char *argv, int n)
{
	if (n == 0)
		cmd->argvv = ft_split_2(argv);
	else
		cmd->argvv2 = ft_split_2(argv);
}

static int	check_access(t_cmd *cmd, char *temp, int n)
{
	if (n == 0 && access(cmd->argvv[0], X_OK) == 0)
	{
		cmd->cmd_addr[0] = cmd->argvv[0];
		return (1);
	}
	if (n == 1 && access(cmd->argvv2[0], X_OK) == 0)
	{
		cmd->cmd_addr[1] = cmd->argvv2[0];
		return (1);
	}
	else
	{
		if (access(temp, X_OK) == 0)
		{
			cmd->cmd_addr[n] = temp;
			return (1);
		}
	}
	return (0);
}

void	cmd_parse(t_cmd *cmd, char *argv, char **envp, int n)
{
	int		i;
	char	*temp;

	temp = str_find(envp, "PATH");
	if (cmd->cmd == NULL)
		cmd->cmd = ft_split(temp, ':');
	free(temp);
	cmd_argv_parse(cmd, argv, n);
	i = -1;
	while (cmd->cmd[++i])
	{
		if (n == 0)
			temp = cmd_init_0(cmd, i);
		else
			temp = cmd_init_1(cmd, i);
		if (check_access(cmd, temp, n))
			return ;
		free(temp);
	}
}
