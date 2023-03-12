/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:33:47 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static int	a_to_i(const char *str, int minus_cnt, int idx)
{
	int	num;

	num = 0;
	while (1)
	{
		if (str[idx] >= '0' && str[idx] <= '9')
		{
			num *= 10;
			num += (str[idx] - '0') * minus_cnt;
			idx++;
		}
		else
			break ;
	}
	return (num);
}

static int	space_str(const char *str)
{
	int	idx;

	idx = 0;
	while (1)
	{
		if (str[idx] == '\t' || str[idx] == '\v' || str[idx] == '\n' || \
				str[idx] == '\f' || str[idx] == '\r' || str[idx] == ' ')
			idx++;
		else
			break ;
	}
	return (idx);
}

int	ft_atoi(const char *str)
{
	int	minus_cnt;
	int	n;
	int	idx;
	int	sign_cnt;

	n = 0;
	idx = space_str(str);
	sign_cnt = 0;
	minus_cnt = 1;
	while (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
		{
			minus_cnt = -1;
			sign_cnt++;
		}
		else if (str[idx] == '+')
			sign_cnt++;
		idx++;
	}
	if (sign_cnt > 1)
		return (0);
	n += a_to_i(str, minus_cnt, idx);
	return (n);
}
