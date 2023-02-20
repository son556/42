/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:45:00 by chanson           #+#    #+#             */
/*   Updated: 2023/02/20 15:30:34 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	binary_to_char(char *arr)
{
	int	i;
	int	data;

	i = 0;
	data = 0;
	if (!strcmp(arr, "00000000"))
		printf("\n");
	else
	{
		while (i < 8)
		{
			data *= 2;
			data += arr[i] - '0';
			i++;
		}
		printf("%c", data);
	}
}

void	ft_handler(int signal)
{
	static int	cnt;
	static char	arr[9];

	if (signal == SIGUSR1)
		arr[7 - cnt] = '1';
	else
		arr[7 - cnt] = '0';
	if (cnt == 7)
	{
		arr[8] = '\0';
		binary_to_char(arr);
		cnt = 0;
	}
	else
		cnt++;
}

void	ft_quit(int signal)
{
	printf("server off\n");
	exit(0);
}

int	main(void)
{
	printf("server pid: %d\n", getpid());
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	signal(SIGINT, ft_quit);
	while (1)
	;
	return (0);
}
