/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:36 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/13 20:27:16 by chanson          ###   ########.fr       */
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

void	real_from(char *cwd_buf, int *flag)
{
	if (ft_strscmp(cwd_buf, "/etc") || ft_strscmp(cwd_buf, "/tmp"))
		*flag = 1;
	if (*flag == 1 && ft_strscmp(cwd_buf, "/private/"))
	{
		free(cwd_buf);
		cwd_buf = ft_strcpy("/");
		*flag = 0;
	}
}

int	change_dir(t_tree *info, char *cwd_buf)
{
	char		*temp;
	static int	flag;

	cwd_buf = check_cd_argv(info->cmd.cmd_arr[1], cwd_buf);
	if (!ft_strncmp(cwd_buf, "//", 2))
	{
		temp = cwd_buf;
		cwd_buf = ft_strcpy_index(cwd_buf, 1, ft_strlen(cwd_buf) - 1);
		free(temp);
	}
	real_from(cwd_buf, &flag);
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
