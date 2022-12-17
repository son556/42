/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:52:14 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 04:32:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3(t_LinkedDeque *a, char array[])
{
	int			arr[3];
	int			i;
	t_DequeNode	*temp;

	arr[0] = a->frontnode->idx;
	arr[1] = a->frontnode->rlink->idx;
	arr[2] = a->frontnode->rlink->rlink->idx;
	merge_sort(arr, 0, 2);
	temp = a->frontnode;
	i = 0;
	while (temp)
	{
		if (temp->idx == arr[0])
			array[i] = 'n';
		else if (temp->idx == arr[1])
			array[i] = 'i';
		else
			array[i] = 'm';
		temp = temp->rlink;
		i++;
	}
	array[3] = '\0';
}

static void	com_a_5(t_LinkedDeque *a, t_LinkedDeque *b, t_cmd **c)
{
	push_pa(a, b);
	ft_cmdadd_back(c, "pa");
	push_pa(a, b);
	ft_cmdadd_back(c, "pa");
	if (a->frontnode->idx > a->frontnode->rlink->idx)
	{
		push_sa(a);
		ft_cmdadd_back(c, "sa");
	}
}

static void	move_to_b(t_LinkedDeque *a, t_LinkedDeque*b, t_cmd **c, int mid)
{
	char	arr[4];

	while (a->count > 3)
	{
		if ((a->frontnode->idx) < mid)
		{
			push_pb(a, b);
			if (*c == NULL)
				*c = ft_cmdnew("pb");
			else
				ft_cmdadd_back(c, "pb");
			continue ;
		}
		push_ra(a);
		if (*c == NULL)
			*c = ft_cmdnew("ra");
		else
			ft_cmdadd_back(c, "ra");
	}
	sort_3(a, arr);
	define_a(a, arr, c);
	com_a_5(a, b, c);
}

t_cmd	*make_deque_b(t_LinkedDeque *a, t_LinkedDeque *b)
{
	int			cnt;
	t_cmd		*cmd;
	int			arr[5];
	t_DequeNode	*temp;

	cnt = deque_size(a);
	cmd = NULL;
	while (cnt-- > 5)
	{
		push_pb(a, b);
		if (cmd == NULL)
			cmd = ft_cmdnew("pb");
		else
			ft_cmdadd_back(&cmd, "pb");
	}
	temp = a->frontnode;
	cnt = 0;
	while (cnt < 5)
	{
		arr[cnt++] = temp->idx;
		temp = temp->rlink;
	}
	merge_sort(arr, 0, 4);
	move_to_b(a, b, &cmd, arr[2]);
	return (cmd);
}
