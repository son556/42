/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:20 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/11 20:54:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	export_args(t_tree *info, char **cmd)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	key = NULL;
	value = NULL;
	while (cmd[i])
	{
		if (!temp_check(&cmd[i]))
			return (i);
		find_key_value(info, cmd[i], &key, &value);
		if (!valid_check(info, &key))
			return (i);
		if (!check_exist_key(info, &key, &value))
		{
			add_env_list(info->export_list, ft_strcpy(key), ft_strcpy(value));
			add_env_list(info->env_list, ft_strcpy(key), ft_strcpy(value));
			free(key);
			free(value);
		}
		i++;
	}
	sort_export_list(info->export_list);
	return (0);
}

int	do_export(t_tree *info)
{
	int		check_args;
	char	**temp;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "export"))
		return (1);
	temp = export_split(info->origin);
	info->export_temp = envp_copy(temp);
	if (temp[1])
	{
		check_args = export_args(info, temp);
		if (check_args)
		{
			printf("export: not a valid identifier\n");
			ft_free_str(temp);
			return (2);
		}
		ft_free_str(info->envp_val);
		info->envp_val = env_to_envp(info->env_list);
	}	
	else
		print_export(info->export_list);
	ft_free_str(temp);
	return (0);
}
