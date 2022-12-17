/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:02:33 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 02:54:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_pa(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	t_DequeNode	*temp;
	int			n;

	if (!deque_b || deque_b->count == 0 || !deque_a)
		return (0);
	temp = create_node_idx(deque_b->frontnode->data, deque_b->frontnode->idx);
	if (!temp)
		return (0);
	delete_front(deque_b);
	n = add_front_deque(deque_a, temp);
	if (!n)
		return (0);
	return (1);
}

int	push_pb(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	t_DequeNode	*temp;
	int			n;

	if (!deque_a || deque_a->count == 0 || !deque_b)
		return (0);
	temp = create_node_idx(deque_a->frontnode->data, deque_a->frontnode->idx);
	if (!temp)
		return (0);
	delete_front(deque_a);
	n = add_front_deque(deque_b, temp);
	if (!n)
		return (0);
	return (1);
}

int	push_sa(t_LinkedDeque *deque_a)
{
	int	n;

	if (!deque_a || deque_a->count < 2)
		return (0);
	n = deque_a->frontnode->data;
	deque_a->frontnode->data = deque_a->frontnode->rlink->data;
	deque_a->frontnode->rlink->data = n;
	n = deque_a->frontnode->idx;
	deque_a->frontnode->idx = deque_a->frontnode->rlink->idx;
	deque_a->frontnode->rlink->idx = n;
	return (1);
}

int	push_sb(t_LinkedDeque *deque_b)
{
	int	n;

	if (!deque_b || deque_b->count < 2)
		return (0);
	n = deque_b->frontnode->data;
	deque_b->frontnode->data = deque_b->frontnode->rlink->data;
	deque_b->frontnode->rlink->data = n;
	n = deque_b->frontnode->idx;
	deque_b->frontnode->idx = deque_b->frontnode->rlink->idx;
	deque_b->frontnode->rlink->idx = n;
	return (1);
}

int	push_ss(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	if (!push_sa(deque_a) || !push_sb(deque_b))
		return (0);
	return (1);
}
