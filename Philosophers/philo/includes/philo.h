/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:07:17 by chanson           #+#    #+#             */
/*   Updated: 2023/02/04 13:59:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE	1
# define FALSE	0

typedef struct s_rules
{
	int	philo_cnt;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	must_eat;
	int	philo_status;
}	t_rules;

typedef struct s_monitor
{
	int				death_cnt;
	int				flags;
	int				full_philos;
	int				philo_cnt;
	pthread_mutex_t	*forks;
	pthread_t		mon;
	pthread_mutex_t	full_key;
	pthread_mutex_t	death_cnt_key;
	pthread_mutex_t	life_key;
	pthread_mutex_t	time_key;
	pthread_mutex_t	print_key;
}	t_monitor;

typedef struct s_philo
{
	long long		life;
	int				cnt_eat;
	int				index;
	int				first_fork;
	int				second_fork;
	t_rules			rules;
	pthread_t		phils;
	t_monitor		*monitor;
}	t_philo;

//set
int			set_init(t_philo *philos, int argc, char **argv, t_monitor *m);
int			set_monitor(t_monitor *m, int n);

//valid_check
int			check_digit(char *str);
int			input_check(char **argv);

//utils
long long	time_check(t_philo *p);
long long	calc_timeval(struct timeval *start, struct timeval *end);
void		philo_status_eat(long long ms, int number);
void		philo_status_sleep(long long ms, int number);
void		philo_status_think(long long ms, int number);
void		philo_status_death(long long ms, int number);
void		philo_status_fork(t_philo *p, int fork1, int fork2);
void		newsleep(t_philo *p, long long time);
int			ft_strcmp(char *str1, char *str2);
int			ft_atoi(char *str);

//thread
void		*thread_philo(void *arg);
void		init_thread(t_philo *p, t_monitor *m);
void		*thread_philo_one(void *arg);

//mutex
void		init_mutex(t_philo *p, pthread_mutex_t *forks, t_monitor *m);

//philo_status
void		*monitoring(void *arg);
void		take_forks(t_philo *p, int i);
int			takeoff_forks(t_philo *p);
int			take_forks_status(t_philo *p);
int			take_sleep(t_philo *p);
int			take_eat(t_philo *p);
void		take_think(t_philo *p);
int			check_die(t_philo *p);

#endif
