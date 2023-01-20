/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:34:55 by chanson           #+#    #+#             */
/*   Updated: 2023/01/11 16:35:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

char	*cmd_init_1(t_cmd *cmd, int i)
{
	char	*temp;
	char	*temp_2;

	temp_2 = ft_strjoin(cmd->cmd[i], "/");
	temp = ft_strjoin(temp_2, cmd->argvv2[0]);
	free(temp_2);
	return (temp);
}
