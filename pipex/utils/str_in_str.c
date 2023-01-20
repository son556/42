/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_in_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:00:46 by chanson           #+#    #+#             */
/*   Updated: 2023/01/11 18:26:04 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

int	str_in_str(char *str, char *check)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (str[i])
	{
		if (str[i] == check[0])
		{
			flag = 1;
			j = 0;
			while (str[i + j] && str[j])
			{
				if (str[i + j] != str[j])
					flag = 0;
				j++;
			}
			if (flag == 1)
				return (1);
		}
		i++;
	}
	return (0);
}
