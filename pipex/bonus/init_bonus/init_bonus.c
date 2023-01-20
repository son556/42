/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:39:51 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 19:40:28 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

char	*cmd_init_0(t_cmd *cmd, int i)
{
	char	*temp;
	char	*temp_2;

	temp_2 = ft_strjoin(cmd->cmd[i], "/");
	temp = ft_strjoin(temp_2, cmd->argvv[0]);
	free(temp_2);
	return (temp);
}
