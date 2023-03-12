/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:53:28 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

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

char	**ft_split_char(char *str, char c)
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
