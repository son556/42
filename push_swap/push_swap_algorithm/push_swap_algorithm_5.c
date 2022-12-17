/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:38:31 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 03:46:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	c_2(t_LinkedDeque *a, t_LinkedDeque *b, t_cmd *l, t_low *c)
{
	if (c->idx_a == c->size_a)
	{
		push_pa(a, b);
		ft_cmdadd_back(&l, "pa");
		push_ra(a);
		ft_cmdadd_back(&l, "ra");
	}
}

static void	complete_deque(t_LinkedDeque *a, t_greedy *g, t_cmd *l, int n)
{
	if (n)
	{
		while (1)
		{
			if (a->frontnode->data == g->min)
				break ;
			push_ra(a);
			ft_cmdadd_back(&l, "ra");
		}
	}
	else
	{
		while (1)
		{
			if (a->frontnode->data == g->min)
				break ;
			push_rra(a);
			ft_cmdadd_back(&l, "rra");
		}
	}
}

void	complete_deque_a(t_LinkedDeque *a, t_greedy *g, t_cmd *l)
{
	t_DequeNode	*temp;
	int			idx;
	int			mid;

	idx = 0;
	if (sort_check_asc(a))
		return ;
	mid = (deque_size(a) - 1) / 2;
	temp = a->frontnode;
	while (1)
	{
		if (temp->data == g->min)
			break ;
		temp = temp->rlink;
		idx++;
	}
	if (idx <= mid)
		complete_deque(a, g, l, 1);
	else
		complete_deque(a, g, l, 0);
}

void	define_a(t_LinkedDeque *a, char *ar, t_cmd **cmd_lst)
{
	if (ar[0] == 'i' && ar[1] == 'n' && ar[2] == 'm')
		sort_inm(a, cmd_lst);
	else if (ar[0] == 'm' && ar[1] == 'i' && ar[2] == 'n')
		sort_min(a, cmd_lst);
	else if (ar[0] == 'm' && ar[1] == 'n' && ar[2] == 'i')
		sort_mni(a, cmd_lst);
	else if (ar[0] == 'n' && ar[1] == 'm' && ar[2] == 'i')
		sort_nmi(a, cmd_lst);
	else if (ar[0] == 'i' && ar[1] == 'm' && ar[2] == 'n')
		sort_imn(a, cmd_lst);
}

void	sort_a_3(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	int			arr[3];
	int			i;
	char		array[4];
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
	define_a(a, array, cmd_lst);
}
