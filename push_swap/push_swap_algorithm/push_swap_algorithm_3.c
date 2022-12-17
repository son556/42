/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:29:04 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 04:29:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	best_put_a(t_LinkedDeque *a, int data)
{
	t_DequeNode	*temp;
	int			idx;
	int			index;
	int			distance;

	temp = a->frontnode;
	distance = 2147483647;
	idx = 0;
	index = 0;
	while (temp)
	{
		if ((data - (temp->idx)) < distance)
		{
			index = idx + 1;
			distance = data - (temp->idx);
		}
		idx++;
		temp = temp->rlink;
	}
	return (index);
}

static int	find_put_a(t_LinkedDeque *a, int data)
{
	t_DequeNode	*temp;
	int			idx;
	int			index;
	int			distance;

	temp = a->frontnode;
	distance = 2147483647;
	idx = 0;
	index = -1;
	while (temp)
	{
		if (temp->idx > data && ((temp->idx) - data) < distance)
		{
			index = idx;
			distance = temp->idx - data;
		}
		idx++;
		temp = temp->rlink;
	}
	if (index == -1 && a->count == 0)
		return (0);
	if (index == -1)
		return (best_put_a(a, data));
	return (index);
}

static int	count_cmd_a(t_LinkedDeque *a, int data, int mid_b, int cnt_b)
{
	int			mid_a;
	int			cnt_a;
	int			n;

	n = deque_size(a);
	mid_a = (n - 1) / 2;
	cnt_a = find_put_a(a, data);
	if (cnt_a == n)
		cnt_a -= 1;
	if (cnt_a <= mid_a)
	{
		if (mid_b == 1 && cnt_a < cnt_b)
			cnt_a = cnt_b;
		else
			cnt_a += cnt_b;
	}
	else
	{
		cnt_a = n - cnt_a;
		if (mid_b == 0 && cnt_a < cnt_b)
			cnt_a = cnt_b;
		else
			cnt_a += cnt_b;
	}
	return (cnt_a);
}

static void	count_cmd(int index, t_LinkedDeque *a, t_LinkedDeque *b, t_low *c)
{
	int			mid_b;
	int			cnt_b;
	int			cnt;

	mid_b = c->middle;
	if (index <= mid_b)
	{
		cnt_b = index;
		mid_b = 1;
	}
	if (index > mid_b)
	{
		cnt_b = deque_size(b) - index;
		mid_b = 0;
	}
	cnt = count_cmd_a(a, deque_data(b, index), mid_b, cnt_b);
	if (cnt < c->cmd_cnt)
	{
		c->cmd_cnt = cnt;
		c->idx = index;
		c->idx_a = find_put_a(a, deque_data(b, index));
	}
}

void	so_a(t_LinkedDeque *a, t_LinkedDeque *b, t_cmd *l)
{
	t_DequeNode		*temp;
	t_low			*cmd;
	int				index;

	cmd = (t_low *)malloc(sizeof(t_low));
	if (!cmd)
		return ;
	cmd->idx = 0;
	cmd->idx_a = 0;
	while (b->count)
	{
		index = 0;
		cmd->size_a = deque_size(a);
		cmd->middle = (deque_size(b) - 1) / 2;
		temp = b->frontnode;
		cmd->cmd_cnt = 2147483647;
		while (temp)
		{
			count_cmd(index, a, b, cmd);
			temp = temp->rlink;
			index++;
		}
		act_c(a, b, cmd, l);
	}
	free(cmd);
}
