/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:53:35 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 14:31:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	cut_space_first(char ***result)
{
	int		i;
	int		j;
	char	*temp;

	if (*result == NULL)
		return ;
	i = -1;
	while ((*result)[++i] != NULL)
	{
		j = 0;
		while ((*result)[i][j] == ' ')
			j++;
		if (j > 0)
		{
			temp = ft_strcpy((*result)[i]);
			free((*result)[i]);
			(*result)[i] = NULL;
			(*result)[i] = ft_strcpy_index(temp, j, ft_strlen(temp) - 1);
			free(temp);
		}
	}
}

static void	case_split(char **temp, int *flag, int i, char *str)
{
	if (*flag == 0 && str[i] == '\"')
	{
		*flag = 1;
		*temp = ft_strcjoin(*temp, str[i]);
	}
	else if (*flag == 0 && str[i] == '\'')
	{
		*flag = 2;
		*temp = ft_strcjoin(*temp, str[i]);
	}
	else if (*flag == 1 && str[i] == '\"')
	{
		*flag = 0;
		*temp = ft_strcjoin(*temp, str[i]);
	}
	else if (*flag == 2 && str[i] == '\'')
	{
		*flag = 0;
		*temp = ft_strcjoin(*temp, str[i]);
	}
	else
		*temp = ft_strcjoin(*temp, str[i]);
}

static void	case_end(char **temp, char ***result)
{
	if (*temp != NULL)
	{
		*result = ft_strsjoin(*result, ft_strcpy(*temp));
		free(*temp);
		*temp = NULL;
	}
}

static void	builtin_split_set(int *i, char ***result, int *flag, char **temp)
{
	*result = NULL;
	*flag = 0;
	*temp = NULL;
	*i = 0;
}

char	**builtin_split(char *str)
{
	int		i;
	int		flag;
	char	**result;
	char	*temp;

	builtin_split_set(&i, &result, &flag, &temp);
	while (1)
	{
		if (flag == 0 && str[i] == '|')
		{
			result = ft_strsjoin(result, ft_strcpy(temp));
			free(temp);
			temp = NULL;
		}
		else if (str[i] == '\0')
		{
			case_end(&temp, &result);
			break ;
		}
		else
			case_split(&temp, &flag, i, str);
		i++;
	}
	cut_space_first(&result);
	return (result);
}
