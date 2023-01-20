/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:49:05 by chanson           #+#    #+#             */
/*   Updated: 2023/01/18 22:16:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static int	make_temp_plus_check(char *temp, char *limit)
{
	int		len;
	char	*cmp_temp;

	cmp_temp = NULL;
	len = ft_strlen(temp);
	free(temp);
	temp = str_cp_limit(temp, len - 1);
	cmp_temp = ft_strjoin(limit, "\n");
	if (cmp_temp == NULL)
	{
		free(temp);
		return (1);
	}
	if (str_cmp(temp, cmp_temp))
	{
		free(temp);
		free(cmp_temp);
		return (1);
	}
	free(cmp_temp);
	return (0);
}

void	here_doc(t_cmd *cmd, char *limit)
{
	char	*temp;

	cmd->infile = open("here_doc", O_WRONLY | O_CREAT, 0644);
	if (cmd->infile < 0)
	{
		perror("infile not found");
		return ;
	}
	while (1)
	{
		write(1, "> ", 2);
		temp = get_next_line(0);
		if (temp == 0)
		{
			write(1, "get_next_line_error\n", 20);
			return ;
		}
		if (make_temp_plus_check(temp, limit))
			break ;
		write(cmd->infile, temp, ft_strlen(temp));
		free(temp);
	}
	close(cmd->infile);
	cmd->infile = open("here_doc", O_RDONLY);
}
