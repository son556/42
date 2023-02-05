/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:52:04 by chanson           #+#    #+#             */
/*   Updated: 2023/02/01 14:53:37 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	newsleep(t_philo *p, long long time)
{
	long long	target_time;

	usleep(10);
	target_time = time_check(p) + time;
	while (target_time > time_check(p))
	{
		usleep(100);
	}
}
