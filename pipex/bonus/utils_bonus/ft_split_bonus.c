/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:31:50 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 19:32:24 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

static void	ft_split_init(char **result, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		result[i] = NULL;
		i++;
	}
}

char	**ft_split(char *str, char c)
{
	int		cnt;
	int		i;
	char	**result;
	int		j;

	i = -1;
	cnt = 0;
	while (str[++i])
	{
		if (str[i] == c)
			cnt++;
	}
	result = (char **)malloc(sizeof(char *) * (i + 2));
	ft_split_init(result, i + 2);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != c)
			result[j] = ft_strcjoin(result[j], str[i]);
		else
			j++;
	}
	return (result);
}
