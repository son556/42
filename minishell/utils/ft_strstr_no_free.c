/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_no_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:44:11 by chanson           #+#    #+#             */
/*   Updated: 2023/03/02 16:47:23 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	fill_result(char *result, char *str_origin, char *str_new)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (str_origin != NULL)
	{
		while (str_origin[++i])
			result[i] = str_origin[i];
	}
	if (str_new != NULL)
	{
		if (i == -1)
			i = 0;
		while (str_new[++j])
			result[i + j] = str_new[j];
	}
}

char	*ft_strstr_no_free(char *str_origin, char *str_new)
{
	int		cnt;
	int		i;
	int		j;
	char	*result;

	i = 0;
	if (str_origin == NULL && str_new == NULL)
		return (0);
	while (str_origin != NULL && str_origin[i])
		i++;
	j = 0;
	while (str_new != NULL && str_new[j])
		j++;
	cnt = i + j;
	result = (char *)malloc(sizeof(char) * (cnt + 1));
	result[cnt] = '\0';
	fill_result(result, str_origin, str_new);
	return (result);
}
