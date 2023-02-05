/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   takeoff_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:18:43 by chanson           #+#    #+#             */
/*   Updated: 2023/02/02 16:55:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	takeoff_forks(t_philo *p)
{
	pthread_mutex_unlock(&(p->monitor->forks[p->first_fork]));
	pthread_mutex_unlock(&(p->monitor->forks[p->second_fork]));
	return (1);
}
