/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:08:17 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:27:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	*thread_philo(void *arg)
{
	t_philo			*p;

	p = (t_philo *)arg;
	if (((p->index) + 1) % 2 == 0)
		usleep(50);
	while (1)
	{
		pthread_mutex_lock(&(p->monitor->death_cnt_key));
		if (p->monitor->death_cnt > 0)
			break ;
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		if (p->rules.must_eat >= 0 && p->cnt_eat >= p->rules.must_eat)
			break ;
		take_forks(p, p->index);
		if (take_eat(p) == 0)
		{
			takeoff_forks(p);
			return (0);
		}
		takeoff_forks(p);
		take_sleep(p);
		take_think(p);
	}
	pthread_mutex_unlock(&(p->monitor->death_cnt_key));
	return (0);
}
