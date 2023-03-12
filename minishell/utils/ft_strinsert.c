/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:31:57 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 13:23:53 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*ft_strinsert(char *str, char *insert, int start, int end)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	while (i < start)
	{
		result = ft_strcjoin(result, str[i]);
		i++;
	}
	i = -1;
	while (insert[++i])
		result = ft_strcjoin(result, insert[i]);
	i = end;
	while (str[i])
	{
		result = ft_strcjoin(result, str[i]);
		i++;
	}
	return (result);
}
