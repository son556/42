/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:10:04 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:28:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	take_fork_left(t_philo *p, int i)
{
	pthread_mutex_lock(&(p->monitor->forks[i]));
	p->first_fork = i;
	return (1);
}

static int	take_fork_right(t_philo *p, int i)
{
	int	idx;

	idx = 0;
	if (i == 0)
		idx = p->monitor->philo_cnt - 1;
	else
		idx = i - 1;
	pthread_mutex_lock(&(p->monitor->forks[idx]));
	p->second_fork = idx;
	return (1);
}

static int	check_sign(t_philo *p)
{
	int	sign;

	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	sign = p->monitor->death_cnt;
	pthread_mutex_unlock(&(p->monitor->death_cnt_key));
	if (sign > 0)
		return (1);
	return (0);
}

void	take_forks(t_philo *p, int i)
{
	int	idx;

	if (check_sign(p) == 1)
		return ;
	if ((i + 1) % 2 == 0)
	{
		take_fork_right(p, p->index);
		take_fork_left(p, p->index);
	}
	else
	{
		take_fork_left(p, p->index);
		take_fork_right(p, p->index);
	}
	idx = p->index + 1;
	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	if (p->monitor->death_cnt > 0)
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		return ;
	}
	pthread_mutex_unlock(&(p->monitor->death_cnt_key));
	philo_status_fork(p, p->first_fork, p->second_fork);
}
