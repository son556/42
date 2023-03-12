/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:52:43 by chanson           #+#    #+#             */
/*   Updated: 2023/03/03 16:32:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	**ft_strsjoin(char **str1, char *str)
{
	char	**temp;
	int		cnt;
	int		idx;

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
	temp = (char **)malloc(sizeof(char *) * (cnt + 2));
	temp[cnt + 1] = NULL;
	idx = -1;
	while (++idx < cnt)
		temp[idx] = ft_strcpy(str1[idx]);
	temp[idx] = str;
	ft_free_str(str1);
	return (temp);
}
