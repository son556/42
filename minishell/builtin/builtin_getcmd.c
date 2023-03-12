/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_getcmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 21:30:12 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/10 17:00:31 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*do_cmd_strjoin(char *str1, char *str2, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1)
	{
		while (str1[i])
		{
			temp[i] = str1[i];
			i++;
		}
	}
	j = 0;
	if (str2)
	{
		while (str2[j])
		{
			temp[i + j] = str2[j];
			j++;
		}
	}
	temp[i + j] = '\0';
	return (temp);
}

char	*cmd_strjoin(char *str1, char *str2)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	temp = (char *)malloc(i + j + 1);
	if (!temp)
		return (NULL);
	temp = do_cmd_strjoin(str1, str2, temp);
	free(str1);
	return (temp);
}

int	cmd_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (FALSE);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (FALSE);
	else
		return (s1[i] - s2[i]);
}

char	*builtin_getcmd(char **pure_cmd, char *s)
{
	int		i;
	int		j;
	char	*new_tmp;

	i = 0;
	j = 0;
	new_tmp = NULL;
	while (pure_cmd[i])
	{
		while (s[j] && cmd_strncmp(pure_cmd[i], &s[j], \
		ft_strlen(pure_cmd[i])))
		{
			if (i == 0)
				j++;
			else
			{
				new_tmp = ft_strcjoin(new_tmp, s[j]);
				j++;
			}
		}
		new_tmp = cmd_strjoin(new_tmp, pure_cmd[i]);
		j += ft_strlen(pure_cmd[i]);
		i++;
	}
	return (new_tmp);
}
