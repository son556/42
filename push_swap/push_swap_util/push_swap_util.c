/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:51:14 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 01:58:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long long	a_to_i(const char *str, int minus_cnt, int idx)
{
	long long	num;

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

long long	ft_aatoi(const char *str)
{
	int			minus_cnt;
	long long	n;
	int			idx;
	int			sign_cnt;

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

void	ft_free(char **temp)
{
	int	idx;
	int	cnt;

	cnt = 0;
	idx = 0;
	while (temp[cnt])
		cnt++;
	while (idx <= cnt)
	{
		free(temp[idx]);
		idx++;
	}
	free(temp);
}

void	match_idx(t_LinkedDeque *deque_a, int *arr)
{
	int			idx;
	int			end;
	t_DequeNode	*temp;

	end = deque_size(deque_a);
	idx = 0;
	while (idx < end)
	{
		temp = deque_a->frontnode;
		while (temp)
		{
			if (temp->data == arr[idx])
				temp->idx = idx;
			temp = temp->rlink;
		}
		idx++;
	}
}
