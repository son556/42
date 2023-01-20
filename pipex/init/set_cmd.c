/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:28:16 by chanson           #+#    #+#             */
/*   Updated: 2023/01/12 17:16:35 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

void	set_cmd(t_cmd *cmd)
{
	cmd->argvv = NULL;
	cmd->argvv2 = NULL;
	cmd->cmd = NULL;
	cmd->cmd_addr[0] = NULL;
	cmd->cmd_addr[1] = NULL;
	cmd->infile = 0;
	cmd->outfile = 0;
	cmd->res = 0;
}
