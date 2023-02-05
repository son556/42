/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:50:42 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 13:58:50 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	philo_status_eat(long long ms, int number)
{
	printf("%lld	%d\033[0;32m is eating\033[0;0m\n", ms, number);
}

void	philo_status_sleep(long long ms, int number)
{
	printf("%lld	%d\033[0;35m is sleeping\033[0;0m\n", ms, number);
}

void	philo_status_think(long long ms, int number)
{
	printf("%lld	%d\033[0;36m is thinking\033[0;0m\n", ms, number);
}

void	philo_status_death(long long ms, int number)
{
	printf("%lld	%d\033[0;31m died\033[0;0m\n", ms, number);
}

void	philo_status_fork(t_philo *p, int fork1, int fork2)
{
	pthread_mutex_lock(&(p->monitor->print_key));
	printf("%lld	%d has taken %d fork\n", time_check(p), p->index, fork1);
	printf("%lld	%d has taken %d fork\n", time_check(p), p->index, fork2);
	pthread_mutex_unlock(&(p->monitor->print_key));
}
