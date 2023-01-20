/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_7.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:30:54 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 03:46:37 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3(t_LinkedDeque *a, char array[])
{
	int			arr[3];
	int			i;
	t_DequeNode	*temp;

	arr[0] = a->frontnode->data;
	arr[1] = a->frontnode->rlink->data;
	arr[2] = a->frontnode->rlink->rlink->data;
	merge_sort(arr, 0, 2);
	temp = a->frontnode;
	i = 0;
	while (temp)
	{
		if (temp->data == arr[0])
			array[i] = 'n';
		else if (temp->data == arr[1])
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
	if (sort_check_asc(b))
	{
		push_rb(b);
		ft_cmdadd_back(c, "rb");
	}
	while (b->count)
	{
		push_pa(a, b);
		ft_cmdadd_back(c, "pa");
	}
}

static void	move_to_b(t_LinkedDeque *a, t_LinkedDeque*b, t_cmd **c, t_greedy *g)
{
	char	arr[4];

	while (a->count > 3)
	{
		if ((a->frontnode->data) < (g->mid))
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

t_cmd	*make_b_cmd(t_LinkedDeque *a, t_LinkedDeque *b, t_greedy *g)
{
	int		n;
	t_cmd	*cmd_lst;
	char	arr[4];

	n = deque_size(a);
	cmd_lst = NULL;
	if (n > 3)
		move_to_b(a, b, &cmd_lst, g);
	else if (n == 3)
	{
		sort_3(a, arr);
		define_a(a, arr, &cmd_lst);
	}
	else if (n == 2)
	{
		if (!sort_check_asc(a))
		{
			push_ra(a);
			if (cmd_lst == NULL)
				cmd_lst = ft_cmdnew("ra");
			else
				ft_cmdadd_back(&cmd_lst, "ra");
		}
	}
	return (cmd_lst);
}
/*
t_cmd	*make_b_cmd(t_LinkedDeque *a)
{
	int		n;
	t_cmd	*cmd_lst;
	char	arr[4];

	n = deque_size(a);
	cmd_lst = NULL;
	if (n == 3)
	{
		sort_3(a, arr);
		define_a(a, arr, &cmd_lst);
	}
	if (n == 2)
	{
		if (!sort_check_asc(a))
		{
			push_ra(a);
			if (cmd_lst == NULL)
				cmd_lst = ft_cmdnew("ra");
			else
				ft_cmdadd_back(&cmd_lst, "ra");
		}
		return (cmd_lst);
	}
	return (cmd_lst);
}
*/