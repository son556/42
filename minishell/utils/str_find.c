/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:24:00 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 16:32:09 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static char	*_result_str(char *str)
{
	char	*result;
	int		end;

	end = 0;
	while (str[end])
		end++;
	result = ft_strcpy_index(str, 5, end);
	return (result);
}

char	*str_find(char **strs, char *find)
{
	int	i;
	int	j;
	int	result;

	i = -1;
	while (strs[++i])
	{
		j = -1;
		if (strs[i][0] == find[0])
		{
			while (strs[i][++j] && find[j])
			{
				if (strs[i][j] == find[j])
					result = 1;
				else
				{
					result = 0;
					break ;
				}
			}
			if (result == 1)
				return (_result_str(strs[i]));
		}
	}
	return (0);
}
