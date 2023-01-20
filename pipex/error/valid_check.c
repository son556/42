/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:45:55 by chanson           #+#    #+#             */
/*   Updated: 2023/01/12 17:17:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

int	valid_check(t_cmd *cmd, char *argv, char **envp, int n)
{
	cmd_parse(cmd, argv, envp, n);
	if (cmd->cmd_addr[n] == NULL)
	{
		cmd->res = 127;
		write(2, "cmd not valid\n", 14);
	}
	return (1);
}
