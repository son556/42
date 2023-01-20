/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:52:05 by chanson           #+#    #+#             */
/*   Updated: 2023/01/18 21:10:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	ft_free(char **argvv)
{
	int	i;

	i = 0;
	while (1)
	{
		if (argvv[i] == NULL)
		{
			free(argvv[i]);
			break ;
		}
		free(argvv[i]);
		i++;
	}
	free(argvv);
}

void	free_cmd(t_cmd *cmd)
{
	ft_free(cmd->argvv);
	cmd->argvv = NULL;
	free(cmd->cmd_addr);
	cmd->cmd_addr = NULL;
}
