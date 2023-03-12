/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:39:23 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*ft_strcjoin(char *s, char c)
{
	char	*temp;
	int		i;

	if (s == NULL)
	{
		temp = (char *)malloc(sizeof(char) * 2);
		temp[0] = c;
		temp[1] = '\0';
	}
	else
	{
		temp = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
		i = -1;
		while (s[++i])
			temp[i] = s[i];
		temp[i++] = c;
		temp[i] = '\0';
	}
	free(s);
	return (temp);
}
