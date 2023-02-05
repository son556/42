/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:27:16 by chanson           #+#    #+#             */
/*   Updated: 2023/02/01 14:20:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	init_mutex(t_philo *p, pthread_mutex_t *forks, t_monitor *m)
{
	int	j;

	j = 0;
	while (j < p->monitor->philo_cnt)
	{
		pthread_mutex_init(&(forks[j]), NULL);
		j++;
	}
	m->forks = forks;
}
