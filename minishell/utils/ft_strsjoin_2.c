/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:43 by chanson           #+#    #+#             */
/*   Updated: 2023/03/03 16:31:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	_fill_temp(char ***temp, char **str1, char *str, int cnt)
{
	int	idx;

	if (str != NULL)
	{
		*temp = (char **)malloc(sizeof(char *) * (cnt + 2));
		*temp[cnt + 1] = NULL;
		idx = -1;
		while (++idx < cnt)
			*temp[idx] = ft_strcpy(str1[idx]);
		*temp[idx] = str;
	}
	else
	{
		*temp = (char **)malloc(sizeof(char *) * (cnt + 1));
		*temp[cnt] = NULL;
		idx = -1;
		while (++idx < cnt)
			*temp[idx] = ft_strcpy(str1[idx]);
	}
}

char	**ft_strsjoin_2(char **str1, char *str)
{
	char	**temp;
	int		cnt;

	if (str1 == NULL)
	{
		temp = (char **)malloc(sizeof(char *) * 2);
		temp[0] = str;
		temp[1] = NULL;
		return (temp);
	}
	cnt = 0;
	while (str1[cnt])
		cnt++;
	_fill_temp(&temp, str1, str, cnt);
	ft_free_str(str1);
	return (temp);
}
