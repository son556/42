/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:25:46 by chanson           #+#    #+#             */
/*   Updated: 2023/02/02 12:27:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*thread_philo_one(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	pthread_mutex_lock(&(p->monitor->life_key));
	p->life = 0;
	pthread_mutex_unlock(&(p->monitor->life_key));
	pthread_mutex_lock(&(p->monitor->forks[0]));
	printf("%lld ms	%d has taken 0 fork\n", time_check(p), p->index);
	pthread_mutex_unlock(&(p->monitor->forks[0]));
	while (1)
	{
		pthread_mutex_lock(&(p->monitor->death_cnt_key));
		if (p->monitor->death_cnt > 0)
		{
			pthread_mutex_unlock(&(p->monitor->death_cnt_key));
			break ;
		}
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
	}
	return (0);
}
