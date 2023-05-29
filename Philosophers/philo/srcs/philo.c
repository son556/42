/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:58:27 by chanson           #+#    #+#             */
/*   Updated: 2023/05/28 20:00:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_start(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("argument count error!!\n");
		return (0);
	}
	if (!input_check(argv))
	{
		printf("found not digit char!!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		printf("wrong philosopher number\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_monitor		monitor;

	if (check_start(argc, argv) == 0)
		return (0);
	philos = (t_philo *)malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* ft_atoi(argv[1]));
	if (philos == NULL || forks == NULL || \
	set_monitor(&monitor, ft_atoi(argv[1])) == 0 \
	|| set_init(philos, argc, argv, &monitor) == 0)
	{
		printf("malloc error\n");
		return (0);
	}
	time_check(philos);
	init_mutex(philos, forks, &monitor);
	init_thread(philos, &monitor);
	return (0);
}
