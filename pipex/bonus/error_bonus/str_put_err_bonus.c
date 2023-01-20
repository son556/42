/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_put_err_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:34:52 by chanson           #+#    #+#             */
/*   Updated: 2023/01/16 20:53:02 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

void	str_put_error(char *str, t_cmd *cmd)
{
	if (cmd->res == 127)
		exit(127);
	perror(str);
	exit(EXIT_FAILURE);
}
