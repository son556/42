/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:52:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/02 20:36:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	do_env(t_tree *info)
{
	t_env	*tmp;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "env"))
		return (1);
	if (info->cmd.cmd_arr[1])
		return (print_error_3("env: ", info->cmd.cmd_arr[1], \
		": No such file or directory"));
	tmp = info->env_list;
	while (tmp)
	{
		if (tmp->value && !ft_strscmp(tmp->key, "?"))
			printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	return (0);
}

char	**make_envp(char **new_envp, int size, t_env *env_list)
{
	int		idx;
	char	*key_value;
	char	*key_value_tmp;
	t_env	*tmp;

	idx = 0;
	tmp = env_list;
	while (idx < size)
	{
		if (tmp->value == NULL)
		{
			tmp = tmp->next;
			continue ;
		}
		key_value_tmp = ft_strjoin(tmp->key, "=");
		key_value = ft_strjoin(key_value_tmp, tmp->value);
		free(key_value_tmp);
		new_envp[idx] = key_value;
		tmp = tmp->next;
		idx++;
	}
	new_envp[idx] = NULL;
	return (new_envp);
}

char	**env_to_envp(t_env *env_list)
{
	int		size;
	int		idx;
	t_env	*tmp;
	char	**new_envp;

	size = 0;
	idx = 0;
	tmp = env_list;
	while (tmp)
	{
		if (tmp->value == NULL)
		{
			tmp = tmp->next;
			continue ;
		}
		size++;
		tmp = tmp->next;
	}
	tmp = env_list;
	new_envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new_envp)
		return (NULL);
	new_envp = make_envp(new_envp, size, env_list);
	return (new_envp);
}

char	**envp_copy(char **envp)
{
	int		i;
	int		size;
	char	**new_envp;

	i = -1;
	size = str_size(envp);
	new_envp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new_envp)
		return (NULL);
	while (++i < size)
	{
		new_envp[i] = ft_strcpy(envp[i]);
		if (!new_envp)
		{
			ft_free_str(new_envp);
			return (NULL);
		}
	}
	new_envp[i] = NULL;
	return (new_envp);
}
