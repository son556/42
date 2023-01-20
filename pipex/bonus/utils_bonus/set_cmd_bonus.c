/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:57:50 by chanson           #+#    #+#             */
/*   Updated: 2023/01/19 21:19:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

void	set_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->cmd_addr = NULL;
	cmd->pipe_fd = NULL;
	cmd->infile = 0;
	cmd->outfile = 0;
	cmd->argvv = NULL;
	cmd->res = 0;
}
