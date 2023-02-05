/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:35:12 by chanson           #+#    #+#             */
/*   Updated: 2023/02/02 13:24:19 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

long long	calc_timeval(struct timeval *start, struct timeval *end)
{
	long long	diff_time;

	diff_time = (end->tv_sec - start->tv_sec) * 1e3 + \
				(end->tv_usec - start->tv_usec) / 1e3;
	return (diff_time);
}
