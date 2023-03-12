/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:18:48 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 21:37:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static int	number_cnt(long long num)
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

static void	fill_temp(char *temp, long long num, int idx)
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

char	*ft_itoa(int n)
{
	char		*temp;
	long long	num;
	int			cnt;

	cnt = 0;
	num = (long long)n;
	if (n < 0)
		cnt += 1;
	cnt += number_cnt(num);
	temp = (char *)malloc(cnt + 1);
	if (!temp)
		return (temp);
	temp[cnt] = '\0';
	cnt--;
	if (num == 0)
	{
		temp[0] = '0';
		return (temp);
	}
	if (num != 0)
		fill_temp(temp, num, cnt);
	return (temp);
}
