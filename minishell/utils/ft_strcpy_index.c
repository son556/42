/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:54:20 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*ft_strcpy_index(char *str, int start, int end)
{
	char	*temp;
	int		i;

	temp = (char *)malloc(sizeof(char) * (end - start + 2));
	temp[end - start + 1] = '\0';
	i = 0;
	while (start + i <= end)
	{
		temp[i] = str[start + i];
		i++;
	}
	return (temp);
}
