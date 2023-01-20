/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:40:52 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 20:41:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

char	*ft_strcjoin(char *str1, char c)
{
	char	*result;
	int		i;

	if (str1 == NULL)
	{
		result = (char *)malloc(2);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	i = ft_strlen(str1);
	result = (char *)malloc(i + 2);
	i = -1;
	while (str1[++i])
		result[i] = str1[i];
	result[i] = c;
	result[i + 1] = '\0';
	free(str1);
	return (result);
}
