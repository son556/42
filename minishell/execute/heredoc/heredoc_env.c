/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:45:52 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 13:22:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	find_end(char *temp, int index)
{
	int	end;

	end = index + 1;
	while (temp[end] != '\n')
	{
		if (temp[end] == ' ' || temp[end] == '\'' \
			|| temp[end] == '\"' || temp[end] == '$' || temp[end] == '\0')
			break ;
		end++;
	}
	return (end - 1);
}

static char	*change_env_2(char **envp, char *temp, int index)
{
	int		end;
	int		i;
	char	*str;
	char	*str2;

	end = find_end(temp, index);
	str = ft_strcpy_index(temp, index + 1, end);
	str2 = ft_strfind(envp, str);
	free(str);
	if (str2 != NULL)
	{
		i = -1;
		while (str2[++i])
		{
			if (str2[i] == '=')
				break ;
		}
		str = ft_strcpy_index(str2, i + 1, ft_strlen(str2));
		free(str2);
		str2 = ft_strinsert(temp, str, index, end + 1);
		free(str);
		return (str2);
	}
	str = ft_strcpy_index(temp, 0, index - 1);
	return (ft_strcjoin(str, '\n'));
}

static char	*find_dollar(char *string, char **envp, int *flag)
{
	int		i;
	char	*str_dollar;
	char	*temp;

	i = 0;
	while (string[i])
	{
		if (string[i] == '$')
		{
			str_dollar = ft_strcpy(string);
			*flag = 1;
			temp = change_env_2(envp, str_dollar, i);
			free(str_dollar);
			break ;
		}
		i++;
	}
	if (*flag == 1)
		return (temp);
	return (0);
}

void	*change_env(char **envp, char *temp)
{
	char	*string;
	char	*str;
	int		flag;

	flag = 1;
	string = ft_strcpy(temp);
	free(temp);
	temp = NULL;
	while (flag)
	{
		flag = 0;
		str = ft_strcpy(string);
		free(string);
		string = NULL;
		string = find_dollar(str, envp, &flag);
		if (flag == 0)
			break ;
		free(str);
	}
	return (str);
}
