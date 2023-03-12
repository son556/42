/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_split.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:39:30 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/10 16:04:30 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	split_while(char *str, char **tmp, int *i, int *flag)
{
	while (str[*i])
	{
		if (str[*i] == ' ' && *flag == 0)
		{
			(*i)++;
			break ;
		}
		*tmp = ft_strcjoin(*tmp, str[*i]);
		if (str[*i] == '"')
		{
			if (*flag == 1)
				*flag = 0;
			else
				*flag = 1;
		}
		if (str[*i] == '\'')
		{
			if (*flag == 2)
				*flag = 0;
			else
				*flag = 2;
		}
		(*i)++;
	}	
}

static char	**do_export_split(char *str, char **new_temp, char *tmp, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] == ' ' && flag == 0)
		{
			i++;
			continue ;
		}
		else
			split_while(str, &tmp, &i, &flag);
		new_temp = ft_strsjoin(new_temp, ft_strcpy(tmp));
		free(tmp);
		tmp = NULL;
	}
	return (new_temp);
}

char	**export_split(char *str)
{
	char	**new_temp;
	char	*tmp;
	int		flag;

	new_temp = NULL;
	tmp = NULL;
	flag = 0;
	new_temp = do_export_split(str, new_temp, tmp, flag);
	return (new_temp);
}
