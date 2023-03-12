/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:39:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	cd_home(t_env *env_list)
{
	t_env	*tmp;

	tmp = env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, "HOME"))
		{
			chdir(tmp->value);
			return ;
		}
		tmp = tmp->next;
	}
}

int	check_dir(char *cwd_buf)
{
	int	check_exist;
	int	res;

	res = 1;
	check_exist = access(cwd_buf, F_OK);
	if (check_exist == -1)
		res = 0;
	free(cwd_buf);
	return (res);
}

int	change_dir(t_tree *info, char *cwd_buf)
{
	cwd_buf = check_cd_argv(info->cmd.cmd_arr[1], cwd_buf);
	if (chdir(cwd_buf) == -1)
	{
		if (check_dir(cwd_buf) == 0)
			return (print_error_3("cd : ", info->cmd.cmd_arr[1], \
				": No such file or directory"));
		else
			return (print_error_3("cd : ", info->cmd.cmd_arr[1], \
				": Not a directory"));
	}
	free(cwd_buf);
	return (2);
}
