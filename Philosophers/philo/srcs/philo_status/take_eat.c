/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:49:53 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:28:21 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	_take_eat(t_philo *p, long long target)
{
	pthread_mutex_lock(&(p->monitor->life_key));
	p->life = target - p->rules.time_to_eat;
	pthread_mutex_unlock(&(p->monitor->life_key));
	newsleep(p, p->rules.time_to_eat * 0.5);
	while (1)
	{
		pthread_mutex_lock(&(p->monitor->death_cnt_key));
		if (p->monitor->death_cnt > 0)
		{	
			pthread_mutex_unlock(&(p->monitor->death_cnt_key));
			break ;
		}
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		if (time_check(p) >= target)
			break ;
	}
	(p->cnt_eat) += 1;
	if (p->rules.must_eat >= 0 && p->cnt_eat == p->rules.must_eat)
	{
		pthread_mutex_lock(&(p->monitor->full_key));
		(p->monitor->full_philos) += 1;
		pthread_mutex_unlock(&(p->monitor->full_key));
		return (0);
	}
	return (1);
}

int	take_eat(t_philo *p)
{
	long long	target;

	target = time_check(p) + p->rules.time_to_eat;
	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	if (p->monitor->death_cnt == 0)
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		pthread_mutex_lock(&(p->monitor->print_key));
		philo_status_eat(time_check(p), (p->index + 1));
		pthread_mutex_unlock(&(p->monitor->print_key));
	}
	else
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		return (0);
	}
	if (_take_eat(p, target) == 0)
		return (0);
	return (1);
}
