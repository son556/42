/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:48:03 by chanson           #+#    #+#             */
/*   Updated: 2023/03/13 17:33:13 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	check_access(t_tree *tree, char *temp)
{
	if (access(temp, X_OK) == 0)
	{
		tree->cmd.cmd_head = temp;
		return (TRUE);
	}
	return (FALSE);
}

static char	*cmd_init_0(t_tree *tree, int i)
{
	char	*temp;
	char	*temp_2;

	temp_2 = NULL;
	temp = NULL;
	temp_2 = ft_strstr_no_free(tree->cmd.envp_path[i], "/");
	temp = ft_strstr(temp_2, tree->cmd.cmd_arr[0]);
	return (temp);
}

void	cmd_check(t_tree *tree, char **cmd)
{
	int		i;
	char	*temp;

	temp = str_find(tree->envp_val, "PATH");
	if (tree->cmd.envp_path == NULL && temp != NULL)
		tree->cmd.envp_path = ft_split_char(temp, ':');
	free(temp);
	tree->cmd.cmd_arr = remove_quote(cmd);
	if (access(cmd[0], X_OK) == 0)
	{
		tree->cmd.cmd_head = ft_strcpy(cmd[0]);
		return ;
	}
	i = -1;
	while (tree->cmd.envp_path && tree->cmd.envp_path[++i])
	{
		temp = cmd_init_0(tree, i);
		if (check_access(tree, temp))
			return ;
		free(temp);
	}
}
