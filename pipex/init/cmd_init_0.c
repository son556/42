/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:15 by chanson           #+#    #+#             */
/*   Updated: 2023/01/11 16:34:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

char	*cmd_init_0(t_cmd *cmd, int i)
{
	char	*temp;
	char	*temp_2;

	temp_2 = ft_strjoin(cmd->cmd[i], "/");
	temp = ft_strjoin(temp_2, cmd->argvv[0]);
	free(temp_2);
	return (temp);
}
