/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_find_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:30:17 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 19:30:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

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
				return (ft_strcpy(strs[i]));
		}
	}
	return (0);
}
