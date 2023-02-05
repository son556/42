/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:53:06 by chanson           #+#    #+#             */
/*   Updated: 2023/01/22 18:08:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	sig;

	if (ft_strcmp("-2147483648", str))
		return (-2147483648);
	if (ft_strcmp("0", str))
		return (0);
	i = 0;
	num = 0;
	sig = 1;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
			sig = -1;
			continue ;
		}
		num *= 10;
		num += sig * (str[i] - '0');
		i++;
	}
	return (num);
}
