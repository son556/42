/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:44:35 by chanson           #+#    #+#             */
/*   Updated: 2023/01/15 20:47:35 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

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
