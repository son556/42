/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intput_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:32:48 by chanson           #+#    #+#             */
/*   Updated: 2023/01/23 17:45:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	input_check(char **argv)
{
	int	idx;

	idx = 1;
	while (argv[idx])
	{
		if (!check_digit(argv[idx]))
			return (FALSE);
		idx++;
	}
	return (TRUE);
}
