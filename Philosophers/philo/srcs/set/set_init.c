/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:35:03 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 13:59:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static void	set_rules(t_rules *r, char **argv, int argc)
{
	r->philo_cnt = ft_atoi(argv[1]);
	r->time_to_die = ft_atoi(argv[2]);
	r->time_to_eat = ft_atoi(argv[3]);
	r->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		r->must_eat = ft_atoi(argv[5]);
	else
		r->must_eat = -1;
}

int	set_monitor(t_monitor *m, int n)
{
	m->death_cnt = 0;
	m->flags = 0;
	m->philo_cnt = n;
	m->full_philos = 0;
	pthread_mutex_init(&(m->full_key), 0);
	pthread_mutex_init(&(m->death_cnt_key), 0);
	pthread_mutex_init(&(m->life_key), 0);
	pthread_mutex_init(&(m->time_key), 0);
	pthread_mutex_init(&(m->print_key), 0);
	return (1);
}

int	set_init(t_philo *philos, int argc, char **argv, t_monitor *m)
{
	int			i;
	int			cnt;

	cnt = ft_atoi(argv[1]);
	i = -1;
	while (++i < cnt)
	{
		(philos[i]).life = 0;
		(philos[i]).cnt_eat = 0;
		(philos[i]).index = i;
		(philos[i]).monitor = m;
		set_rules(&(philos[i].rules), argv, argc);
	}
	return (1);
}
