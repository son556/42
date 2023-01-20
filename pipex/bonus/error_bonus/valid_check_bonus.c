/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:36:00 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 20:52:01 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

int	valid_check(t_cmd *cmd, char *argv, char **envp)
{
	cmd_parse(cmd, argv, envp);
	if (cmd->cmd_addr == NULL)
	{
		cmd->res = 127;
		write(2, "cmd not valid: ", 15);
		write(2, argv, ft_strlen(argv));
		write(2, "\n", 1);
	}
	return (1);
}
