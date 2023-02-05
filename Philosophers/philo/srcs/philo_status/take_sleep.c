/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_sleep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:27:44 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:27:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	routine_sleep(t_philo *p, long long target)
{
	int	sign;

	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	sign = p->monitor->death_cnt;
	pthread_mutex_unlock(&(p->monitor->death_cnt_key));
	while (sign == 0)
	{
		pthread_mutex_lock(&(p->monitor->death_cnt_key));
		sign = p->monitor->death_cnt;
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		if (time_check(p) >= target)
			return (1);
	}
	return (0);
}

int	take_sleep(t_philo *p)
{
	long long	target;

	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	target = time_check(p) + p->rules.time_to_sleep;
	if (p->monitor->death_cnt == 0)
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		pthread_mutex_lock(&(p->monitor->print_key));
		philo_status_sleep(time_check(p), p->index + 1);
		pthread_mutex_unlock(&(p->monitor->print_key));
	}
	else
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		return (0);
	}
	newsleep(p, p->rules.time_to_sleep * 0.5);
	if (routine_sleep(p, target) == 1)
		return (0);
	return (1);
}
