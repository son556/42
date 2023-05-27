/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 17:10:49 by chanson           #+#    #+#             */
/*   Updated: 2023/05/27 17:20:38 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PTHREAD_H
# define PTHREAD_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_task
{
	int				start;
	int				end;
	int				task_status;
	struct s_task	*pre;
	struct s_task	*next;
}	t_task;


typedef struct s_task_list
{
	t_task	*start;
}	t_task_list;

#endif