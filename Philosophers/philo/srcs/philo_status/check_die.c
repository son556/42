/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:09:00 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 13:56:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	check_die(t_philo *p)
{
	long long	time;
	long long	minus;

	pthread_mutex_lock(&(p->monitor->life_key));
	minus = p->life;
	pthread_mutex_unlock(&(p->monitor->life_key));
	time = time_check(p) - minus;
	if (time > p->rules.time_to_die)
	{
		pthread_mutex_lock(&(p->monitor->death_cnt_key));
		p->monitor->death_cnt++;
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		pthread_mutex_lock(&(p->monitor->print_key));
		philo_status_death(time_check(p), p->index + 1);
		pthread_mutex_unlock(&(p->monitor->print_key));
		return (1);
	}
	return (0);
}
