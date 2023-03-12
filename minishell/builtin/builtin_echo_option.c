/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:53:32 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/09 11:53:33 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*remove_quote_builtin(char *s)
{
	char	*tmp;

	if (s[0] == '"')
		tmp = ft_strtrim(s, '"');
	else if (s[0] == '\'')
		tmp = ft_strtrim(s, '\'');
	else
		tmp = ft_strcpy(s);
	return (tmp);
}

int	echo_option(char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	if (str == NULL)
		return (-1);
	if (ft_strscmp(str, " "))
		return (1);
	tmp = remove_quote_builtin(str);
	if (tmp[0] == '-')
	{
		while (tmp[i] == 'n')
			i++;
		if (i != ft_strlen(tmp) || i == 1)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	check_echo_option(char **temp, int *i, int *flag)
{
	if (echo_option(temp[*i]) == -1)
	{
		ft_free_str(temp);
		return (0);
	}
	while (echo_option(temp[*i]) == 1)
	{
		if (ft_strscmp(temp[*i], " "))
		{
			(*i)++;
			continue ;
		}
		(*i)++;
		*flag = 0;
	}
	return (1);
}
