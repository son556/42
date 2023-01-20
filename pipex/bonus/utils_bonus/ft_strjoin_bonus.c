/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:29:16 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 19:29:52 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

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
