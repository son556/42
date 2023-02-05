/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:37:38 by chanson           #+#    #+#             */
/*   Updated: 2023/01/22 19:39:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_digit(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			return (FALSE);
		idx++;
	}
	return (TRUE);
}
