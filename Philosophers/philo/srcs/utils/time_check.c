/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:01:32 by chanson           #+#    #+#             */
/*   Updated: 2023/02/02 12:35:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long	time_check(t_philo *p)
{
	static struct timeval	start;
	struct timeval			end;
	static long long		diff_time;
	long long				diff;

	pthread_mutex_lock(&(p->monitor->time_key));
	diff = 0;
	if (diff_time == 0)
	{
		gettimeofday(&start, NULL);
		diff_time = (start.tv_sec * 1000) + (start.tv_usec / 1000);
	}
	else
	{
		gettimeofday(&end, NULL);
		diff = calc_timeval(&start, &end);
	}
	pthread_mutex_unlock(&(p->monitor->time_key));
	return (diff);
}
