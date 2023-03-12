/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:21:39 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 20:04:29 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	relink_env_list(t_env *tmp)
{
	if (tmp->prev && tmp->next)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	else if (tmp->prev && tmp->next == NULL)
			tmp->prev->next = NULL;
	else if (tmp->prev == NULL && tmp->next)
			tmp->next->prev = NULL;
	free(tmp->key);
	free(tmp->value);
}

char	*unset_valid_check(char *str)
{
	char	*tmp;
	int		flag;

	tmp = NULL;
	flag = 0;
	if (str[0] == '\'')
	{
		tmp = ft_strtrim(str, '\'');
		flag = 1;
	}
	else if (str[0] == '"')
	{
		tmp = ft_strtrim(str, '"');
		flag = 1;
	}
	if (flag == 1)
	{
		if (!ft_isalpha(tmp[0]))
			return (NULL);
		return (tmp);
	}
	if (!ft_isalpha(str[0]))
		return (NULL);
	return (ft_strcpy(str));
}

int	iter_cmd(char **cmd, t_env *tmp, t_env *tmp_next)
{
	int		i;
	char	*key_tmp;

	i = 1;
	while (cmd[i])
	{
		key_tmp = unset_valid_check(cmd[i]);
		if (!key_tmp)
			return (i);
		if (ft_strscmp(tmp->key, key_tmp))
		{
			relink_env_list(tmp);
			free(tmp);
			free(key_tmp);
			tmp = tmp_next;
			break ;
		}
		free(key_tmp);
		i++;
	}
	return (0);
}

int	list_unset(char **cmd, t_env **env_list)
{
	t_env	*tmp;
	t_env	*tmp_next;
	int		idx;

	tmp = *env_list;
	while (tmp)
	{
		tmp_next = tmp->next;
		idx = iter_cmd(cmd, tmp, tmp_next);
		if (idx != 0)
			return (idx);
		tmp = tmp_next;
	}
	return (0);
}

int	do_unset(t_tree *info)
{
	int	res1;
	int	res2;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "unset"))
		return (1);
	res1 = list_unset(info->cmd.cmd_arr, &(info->env_list));
	res2 = list_unset(info->cmd.cmd_arr, &(info->export_list));
	ft_free_str(info->envp_val);
	info->envp_val = env_to_envp(info->env_list);
	if (res1 > 0)
		return (print_error_3("unset: \'", info->cmd.cmd_arr[res1], \
			"\': not a valid identifier"));
	return (0);
}
