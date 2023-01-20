/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:19:40 by chanson           #+#    #+#             */
/*   Updated: 2023/01/12 16:09:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

char	*ft_strcpy(char	*str)
{
	int		i;
	int		cnt;
	char	*result;

	i = 5;
	cnt = 0;
	while (str[i])
	{
		i++;
		cnt++;
	}
	result = (char *)malloc(cnt + 1);
	i = 5;
	cnt = 0;
	while (str[i])
	{
		result[cnt] = str[i];
		cnt++;
		i++;
	}
	result[cnt] = '\0';
	return (result);
}
