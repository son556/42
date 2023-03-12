/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 01:49:37 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/12 01:49:38 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*plus_slash_env(char *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tmp)
		return (NULL);
	while (s[i] != '$')
	{
		tmp[i] = s[i];
		i++;
	}
	j = i;
	tmp[i++] = '\\';
	while (s[j])
	{
		tmp[i] = s[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*remove_quote_export(char *s)
{
	char	*tmp;

	if (s[0] == '"')
		tmp = ft_strtrim(s, '"');
	else if (s[0] == '\'')
	{
		if (ft_strlen(s) == ft_strchr(s, '$'))
			tmp = ft_strtrim(s, '\'');
		else
			tmp = plus_slash_env(s);
	}
	else
		tmp = ft_strcpy(s);
	free(s);
	return (tmp);
}

void	find_key_value(t_tree *info, char *str, char **key, char **value)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			break ;
		i++;
	}
	*key = ft_strcpy_index(str, 0, i - 1);
	*value = ft_strcpy_index(str, i + 1, ft_strlen(str) - 1);
	if (i == ft_strlen(str))
	{
		free(*value);
		*value = NULL;
	}
	else
	{
		*value = remove_quote_export(*value);
		if (*value[0] != '\'')
			*value = change_env(info->envp_val, *value);
	}
}

int	do_check_exist_key(t_env **env_list, char *key, char *value)
{
	t_env	*tmp;

	tmp = *env_list;
	while (tmp)
	{
		if (ft_strscmp(tmp->key, key))
		{
			if (value == NULL)
				free(key);
			else
			{
				free(tmp->key);
				tmp->key = key;
				free(tmp->value);
				tmp->value = value;
			}
			return (1);
		}
		tmp = tmp->next;
	}
	free(key);
	free(value);
	return (0);
}

int	check_exist_key(t_tree *info, char **key, char **value)
{
	int	check_n;

	check_n = do_check_exist_key(&(info->env_list), \
	ft_strcpy(*key), ft_strcpy(*value));
	check_n = do_check_exist_key(&(info->export_list), \
	ft_strcpy(*key), ft_strcpy(*value));
	if (check_n == 1)
	{
		free(*key);
		free(*value);
		return (1);
	}
	return (0);
}
