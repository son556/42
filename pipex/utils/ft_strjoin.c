/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:25:28 by chanson           #+#    #+#             */
/*   Updated: 2023/01/11 16:25:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*temp;
	int		i;
	int		j;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	if (!i || !j)
		return (0);
	temp = (char *)malloc(i + j + 1);
	i = -1;
	while (str1[++i])
		temp[i] = str1[i];
	j = -1;
	while (str2[++j])
		temp[i + j] = str2[j];
	temp[i + j] = '\0';
	return (temp);
}
