/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_valid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:50:01 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/12 02:50:01 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	key_check(char *s, char c)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != c && s[i] != '=')
	{
		if (c == '"' && s[i] == '$')
		{
			i++;
			continue ;
		}
		if (!ft_isalnum(s[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*add_single_quote(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 3));
	if (!tmp)
		return (NULL);
	while ((*str)[++i])
	{
		tmp[i] = (*str)[i];
		if ((*str)[i++] == '=')
			break ;
	}
	j = i - 1;
	tmp[i++] = '\'';
	while ((*str)[++j])
	{
		tmp[i] = (*str)[j];
		i++;
	}
	tmp[i++] = '\'';
	tmp[i] = '\0';
	free(*str);
	return (tmp);
}

int	quote_check(char **tmp, char **str, char c)
{
	if (*str[0] == c)
	{
		if (!key_check(*str, c))
			return (0);
		*tmp = ft_strtrim(*str, c);
		free(*str);
		*str = *tmp;
		if (c == '\'' && ft_strchr(*str, '=') != ft_strlen(*str))
			*str = add_single_quote(str);
	}
	return (1);
}

int	temp_check(char **str)
{
	char	*tmp;

	tmp = NULL;
	if (*str[0] == '\'')
	{
		if (!quote_check(&tmp, str, '\''))
			return (0);
	}
	else if (*str[0] == '"')
	{
		if (!quote_check(&tmp, str, '"'))
			return (0);
	}
	return (1);
}

int	valid_check(t_tree *info, char **str)
{
	if (*str[0] == '$' && ft_strlen(*str) == 1)
		return (0);
	*str = change_env(info->envp_val, *str);
	if (ft_strscmp(*str, "\n"))
	{
		free(*str);
		return (-1);
	}
	if (*str && !ft_isalpha(*str[0]))
	{
		free(*str);
		return (0);
	}
	return (1);
}
