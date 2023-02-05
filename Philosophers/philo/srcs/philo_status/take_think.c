/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_think.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 22:02:09 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 14:28:00 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	take_think(t_philo *p)
{
	pthread_mutex_lock(&(p->monitor->death_cnt_key));
	if (p->monitor->death_cnt == 0)
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		pthread_mutex_lock(&(p->monitor->print_key));
		philo_status_think(time_check(p), p->index + 1);
		pthread_mutex_unlock(&(p->monitor->print_key));
	}
	else
	{
		pthread_mutex_unlock(&(p->monitor->death_cnt_key));
		return ;
	}
}
