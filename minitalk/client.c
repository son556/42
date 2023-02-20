/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:48:35 by chanson           #+#    #+#             */
/*   Updated: 2023/02/20 15:29:23 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_end_bit(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	send_bit_server_quit(int pid)
{
	kill(pid, SIGINT);
}

void	send_bit_by_bit(char c, int pid)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		client_pid;
	int		i;
	char	*str;

	if (argc <= 1)
		return (1);
	pid = atoi(argv[1]);
	client_pid = getpid();
	while (1)
	{
		i = -1;
		str = readline("input: ");
		if (!strcmp(str, "end"))
		{
			free(str);
			send_bit_server_quit(pid);
			break ;
		}
		while (str[++i])
			send_bit_by_bit(str[i], pid);
		send_end_bit(pid);
		free(str);
	}
	return (0);
}
