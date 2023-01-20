/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:01:07 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 04:28:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	case_1(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l)
{
	int	idx;

	idx = 0;
	while (idx < c->idx && idx < c->idx_a)
	{
		push_rr(a, b);
		ft_cmdadd_back(&l, "rr");
		idx++;
	}
	while (idx < c->idx)
	{
		push_rb(b);
		ft_cmdadd_back(&l, "rb");
		idx++;
	}
	while (idx < c->idx_a)
	{
		push_ra(a);
		ft_cmdadd_back(&l, "ra");
		idx++;
	}
}

static void	case_2(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l)
{
	int	idx;
	int	n;

	n = deque_size(a) - (c->idx_a);
	idx = deque_size(b) - (c->idx);
	while (idx && n)
	{
		push_rrr(a, b);
		ft_cmdadd_back(&l, "rrr");
		idx--;
		n--;
	}
	while (idx)
	{
		push_rrb(b);
		ft_cmdadd_back(&l, "rrb");
		idx--;
	}
	while (n && c->idx_a != c->size_a)
	{
		push_rra(a);
		ft_cmdadd_back(&l, "rra");
		n--;
	}
	c_2(a, b, l, c);
}

static void	case_3(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l)
{
	int	idx;

	idx = 0;
	while (1)
	{
		if (idx == c->idx)
			break ;
		push_rb(b);
		ft_cmdadd_back(&l, "rb");
		idx++;
	}
	idx = (c->size_a) - (c->idx_a);
	while (idx)
	{
		push_rra(a);
		ft_cmdadd_back(&l, "rra");
		idx--;
	}
	c_2(a, b, l, c);
}

static void	case_4(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l)
{
	int	idx;

	idx = deque_size(b) - (c->idx);
	while (idx)
	{
		push_rrb(b);
		ft_cmdadd_back(&l, "rrb");
		idx--;
	}
	idx = 0;
	while (1)
	{
		if (idx == c->idx_a)
			break ;
		push_ra(a);
		ft_cmdadd_back(&l, "ra");
		idx++;
	}
}

void	act_c(t_LinkedDeque *a, t_LinkedDeque *b, t_low *c, t_cmd *l)
{
	int			mid_a;

	mid_a = (c->size_a - 1) / 2;
	if (c->idx <= c->middle && c->idx_a <= mid_a)
		case_1(a, b, c, l);
	else if (c->idx > c->middle && c->idx_a > mid_a)
		case_2(a, b, c, l);
	else
	{
		if (c->idx <= c->middle && c->idx_a > mid_a)
			case_3(a, b, c, l);
		else
			case_4(a, b, c, l);
	}
	if (c->idx_a != c->size_a)
	{
		push_pa(a, b);
		ft_cmdadd_back(&l, "pa");
	}
}
