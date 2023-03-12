/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:49:56 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/04 14:09:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

t_env	*sort_export_list(t_env *export_list)
{
	t_env	*tmp;
	t_env	*tmp_next;
	char	*key_tmp;
	char	*value_tmp;

	tmp = export_list;
	while (tmp)
	{
		tmp_next = tmp->next;
		while (tmp_next)
		{
			if (ft_strncmp(tmp->key, tmp_next->key, ft_strlen(tmp->key)) > 0)
			{
				key_tmp = tmp->key;
				value_tmp = tmp->value;
				tmp->key = tmp_next->key;
				tmp->value = tmp_next->value;
				tmp_next->key = key_tmp;
				tmp_next->value = value_tmp;
			}
			tmp_next = tmp_next->next;
		}
		tmp = tmp->next;
	}
	return (export_list);
}

t_env	*free_last(t_env *export_list)
{
	t_env	*tmp;

	tmp = export_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->prev->next = NULL;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	tmp->key = NULL;
	tmp->value = NULL;
	tmp = NULL;
	return (export_list);
}

t_env	*make_export_list(char **envp)
{
	t_env	*export_list;

	export_list = make_env_list(envp);
	export_list = free_last(export_list);
	export_list = sort_export_list(export_list);
	return (export_list);
}

void	print_export(t_env *export_list)
{
	t_env	*tmp;
	char	*value_tmp;

	tmp = export_list;
	while (tmp)
	{
		if (!ft_strscmp(tmp->key, "?"))
		{
			if (tmp->value != NULL)
			{
				if (tmp->value[0] == '\'')
				{
					value_tmp = ft_strtrim(tmp->value, '\'');
					printf("declare -x %s=\"%s\"\n", tmp->key, value_tmp);
					free(value_tmp);
				}	
				else
					printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
			}
			else
				printf("declare -x %s\n", tmp->key);
		}
		tmp = tmp->next;
	}
}
