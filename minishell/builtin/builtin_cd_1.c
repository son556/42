/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:54:11 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 19:58:49 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*cd_dot_dot(char *buf_tmp, char *slash, int *i)
{
	int		slash_idx;
	int		num;
	char	*tmp;

	if (ft_strscmp(slash, ".."))
		num = 2;
	else
		num = 3;
	*i += num;
	if (ft_strlen(buf_tmp) == 1)
		return (buf_tmp);
	if (buf_tmp[ft_strlen(buf_tmp) - 1] == '/')
	{
		tmp = ft_strcpy_index(buf_tmp, 0, ft_strlen(buf_tmp) - 2);
		free(buf_tmp);
		buf_tmp = tmp;
	}
	slash_idx = ft_strrchr(buf_tmp, '/');
	tmp = ft_strcpy_index(buf_tmp, 0, slash_idx);
	free(buf_tmp);
	buf_tmp = tmp;
	return (buf_tmp);
}

char	*cd_not_dot(char *buf_tmp, char *str, int *i)
{
	int	slash_idx;
	int	j;

	slash_idx = ft_strchr(&str[*i], '/');
	if (slash_idx == 0)
	{
		if (*i == 0)
		{
			(*i)++;
			free(buf_tmp);
			return (ft_strcpy("/"));
		}
		buf_tmp = ft_strcjoin(buf_tmp, '/');
		(*i)++;
		slash_idx = ft_strchr(&str[*i], '/');
	}
	else
		buf_tmp = ft_strcjoin(buf_tmp, '/');
	j = -1;
	while (++j < slash_idx)
		buf_tmp = ft_strcjoin(buf_tmp, str[*i + j]);
	*i += j;
	return (buf_tmp);
}

char	*add_back_slash(char *buf_tmp, char *slash, int *i)
{
	if (buf_tmp[ft_strlen(buf_tmp) - 1] != '/')
		buf_tmp = ft_strcjoin(buf_tmp, '/');
	if (ft_strscmp(slash, "./"))
		*i += 2;
	else
		*i += 1;
	return (buf_tmp);
}

char	*check_cd_argv(char *str, char *cwd_buf)
{
	char	*buf_tmp;
	int		i;

	i = 0;
	buf_tmp = ft_strcpy(cwd_buf);
	free(cwd_buf);
	while (str[i])
	{
		if (!ft_strncmp(&str[i], "../", 3))
			buf_tmp = cd_dot_dot(buf_tmp, "../", &i);
		else if (!ft_strncmp(&str[i], "./", 2))
			buf_tmp = add_back_slash(buf_tmp, "./", &i);
		else if (ft_strscmp(&str[i], ".."))
			buf_tmp = cd_dot_dot(buf_tmp, "..", &i);
		else if (ft_strscmp(&str[i], "."))
			buf_tmp = add_back_slash(buf_tmp, ".", &i);
		else
			buf_tmp = cd_not_dot(buf_tmp, str, &i);
	}
	return (buf_tmp);
}

int	do_cd(t_tree *info)
{
	char	*cwd_buf;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "cd"))
		return (1);
	if (str_size(info->cmd.cmd_arr) > 2)
		return (print_error_2("cd: string not in: ", info->cmd.cmd_arr[2]));
	cwd_buf = (char *)malloc(sizeof(char) * 1024);
	if (!cwd_buf)
		return (print_error_1("malloc_error"));
	cwd_buf = getcwd(cwd_buf, 1024);
	if (info->cmd.cmd_arr[1])
		return (change_dir(info, cwd_buf));
	else
		cd_home(info->env_list);
	free(cwd_buf);
	return (0);
}
