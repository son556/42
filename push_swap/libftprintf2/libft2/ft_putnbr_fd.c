/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:06:48 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 19:38:13 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_count(long long num)
{
	int	cnt;

	cnt = 0;
	if (num == 0)
		cnt++;
	while (num)
	{
		num /= 10;
		cnt++;
	}
	return (cnt);
}

static void	fill_temp_c(char *temp, long long num, int idx)
{
	if (num < 0)
	{
		temp[0] = '-';
		num *= -1;
	}
	while (num)
	{
		temp[idx] = '0' + num % 10;
		idx--;
		num /= 10;
	}
}

static void	ft_iitoa(int n, char *temp)
{
	long long	num;
	int			cnt;

	cnt = 0;
	num = (long long)n;
	if (n < 0)
		cnt += 1;
	cnt += number_count(num);
	temp[cnt] = '\0';
	cnt--;
	if (num == 0)
		temp[0] = '0';
	else if (num != 0)
		fill_temp_c(temp, num, cnt);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[256];
	int		cnt;

	cnt = 0;
	ft_iitoa(n, temp);
	while (temp[cnt])
		cnt++;
	write(fd, temp, cnt);
}
