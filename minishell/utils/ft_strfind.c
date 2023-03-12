/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:19:36 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*ft_strfind(char **strs, char *find)
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
