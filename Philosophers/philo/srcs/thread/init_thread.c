/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:10:45 by chanson           #+#    #+#             */
/*   Updated: 2023/02/03 21:02:38 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_thread(t_philo *p, t_monitor *m)
{
	int	i;
	int	n;

	n = m->philo_cnt;
	i = -1;
	while (++i < n)
		pthread_mutex_init(&(m->forks[i]), 0);
	i = -1;
	if (m->philo_cnt > 1)
	{
		while (++i < n)
			pthread_create(&(p[i].phils), NULL, &thread_philo, (void *)&(p[i]));
	}
	else
		pthread_create(&(p[0].phils), NULL, &thread_philo_one, (void *)&(p[0]));
	monitoring((void *)p);
	i = -1;
	while (++i < n)
		pthread_join((p[i].phils), NULL);
}
