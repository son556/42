/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:27:33 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 02:40:42 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_ra(t_LinkedDeque *deque_a)
{
	t_DequeNode	*temp;

	if (!deque_a || deque_a->count < 2)
		return (0);
	temp = create_node_idx(deque_a->frontnode->data, deque_a->frontnode->idx);
	add_rear_deque(deque_a, temp);
	delete_front(deque_a);
	return (1);
}

int	push_rb(t_LinkedDeque *deque_b)
{
	t_DequeNode	*temp;

	if (!deque_b || deque_b->count < 2)
		return (0);
	temp = create_node_idx(deque_b->frontnode->data, deque_b->frontnode->idx);
	add_rear_deque(deque_b, temp);
	delete_front(deque_b);
	return (1);
}

int	push_rr(t_LinkedDeque *deque_a, t_LinkedDeque *deque_b)
{
	if (!push_ra(deque_a) || !push_rb(deque_b))
		return (0);
	return (1);
}

int	push_rra(t_LinkedDeque *deque_a)
{
	t_DequeNode	*temp;

	if (!deque_a || deque_a->count < 2)
		return (0);
	temp = create_node_idx(deque_a->rearnode->data, deque_a->rearnode->idx);
	add_front_deque(deque_a, temp);
	delete_rear(deque_a);
	return (1);
}

int	push_rrb(t_LinkedDeque *deque_b)
{
	t_DequeNode	*temp;

	if (!deque_b || deque_b->count < 2)
		return (0);
	temp = create_node_idx(deque_b->rearnode->data, deque_b->rearnode->idx);
	add_front_deque(deque_b, temp);
	delete_rear(deque_b);
	return (1);
}
