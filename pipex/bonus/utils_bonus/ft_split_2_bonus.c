/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:32:54 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 19:33:37 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	split_except(char *str, int *i)
{
	if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] != '\'' && str[*i])
			*i += 1;
	}
	else if (str[*i] == '\"')
	{
		*i += 1;
		while (str[*i] != '\"' && str[*i])
			*i += 1;
	}
}

static void	fill_temp_except(char **temp, char *str, int *i, int cnt)
{
	if (str[*i] == '\'')
	{
		*i += 1;
		while (str[*i] != '\'' && str[*i])
		{
			temp[cnt] = ft_strcjoin(temp[cnt], str[*i]);
				*i += 1;
		}
	}
	else if (str[*i] == '\"')
	{
		*i += 1;
		while (str[*i] != '\"' && str[*i])
		{
			temp[cnt] = ft_strcjoin(temp[cnt], str[*i]);
			*i += 1;
		}
	}
}

static void	fill_temp_awk(char **temp, char *str)
{
	int	i;
	int	cnt;
	int	flag;

	i = -1;
	cnt = 0;
	flag = 0;
	while (str[++i])
	{
		if (str[i] != '\t' && str[i] != ' ')
		{
			if (str[i] == '\'' || str[i] == '\"')
				fill_temp_except(temp, str, &i, cnt);
			else
				temp[cnt] = ft_strcjoin(temp[cnt], str[i]);
			flag = 1;
		}
		else if ((str[i] == '\t' || str[i] == ' ') && flag == 1)
		{
			flag = 0;
			cnt++;
		}
	}
}

char	**ft_split_2(char *str)
{
	int		i;
	int		cnt;
	int		flag;
	char	**temp;

	i = -1;
	flag = 0;
	cnt = 0;
	while (str[++i])
	{
		if (str[i] != '\t' && str[i] != ' ' && flag == 0)
		{
			split_except(str, &i);
			flag = 1;
			cnt++;
		}
		else if (str[i] == '\t' || str[i] == ' ')
			flag = 0;
	}
	temp = (char **)malloc(sizeof(char *) * (cnt + 1));
	i = -1;
	while (++i < cnt + 1)
		temp[i] = NULL;
	fill_temp_awk(temp, str);
	return (temp);
}
