/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_put_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:31:07 by chanson           #+#    #+#             */
/*   Updated: 2023/01/18 19:55:39 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

void	str_put_error(char *str, t_cmd *cmd)
{
	if (cmd->res == 127)
		exit(127);
	perror(str);
	exit(EXIT_FAILURE);
}
