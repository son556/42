/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:26:06 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:24:48 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	_monitoring_in(t_monitor *m, t_philo *p, int *result)
{
	int	i;

	i = -1;
	while (++i < m->philo_cnt)
	{
		pthread_mutex_lock(&(m->death_cnt_key));
		if (m->death_cnt > 0)
		{
			pthread_mutex_unlock(&(m->death_cnt_key));
			*result = 1;
			return (1);
		}
		pthread_mutex_unlock(&(m->death_cnt_key));
		check_die(&(p[i]));
	}
	return (0);
}

static int	_monitoring_in_2(t_monitor *m, t_philo *p, int *result)
{
	pthread_mutex_lock(&(m->full_key));
	if (p->rules.must_eat >= 0 && m->full_philos >= m->philo_cnt)
	{
		pthread_mutex_unlock(&(m->full_key));
		pthread_mutex_lock(&(m->death_cnt_key));
		*result = m->death_cnt++;
		printf("all philosophers are full\n");
		pthread_mutex_unlock(&(m->death_cnt_key));
		return (1);
	}
	pthread_mutex_unlock(&(m->full_key));
	return (0);
}

void	*monitoring(void *arg)
{
	t_monitor	*monitor;
	t_philo		*philo;
	int			result;

	philo = (t_philo *)arg;
	monitor = philo->monitor;
	pthread_mutex_lock(&(monitor->death_cnt_key));
	result = monitor->death_cnt;
	pthread_mutex_unlock(&(monitor->death_cnt_key));
	while (result == 0)
	{
		if (_monitoring_in(monitor, philo, &result) == 1)
			break ;
		if (philo->rules.must_eat >= 0 && \
			_monitoring_in_2(monitor, philo, &result) == 1)
			break ;
	}
	return (0);
}
