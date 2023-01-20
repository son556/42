/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:37:43 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 02:02:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	delete_rear(t_LinkedDeque *deque)
{
	t_DequeNode	*temp;

	if (!deque)
		return (0);
	if (deque->count > 1)
	{
		temp = deque->rearnode;
		deque->rearnode = temp->flink;
		deque->rearnode->rlink = NULL;
		deque->count--;
		free(temp);
		return (1);
	}
	if (deque->count == 1)
	{
		free(deque->frontnode);
		deque->frontnode = NULL;
		deque->rearnode = NULL;
		deque->count--;
		return (1);
	}
	return (0);
}

int	delete_deque(t_LinkedDeque *deque)
{
	t_DequeNode	*temp;

	if (!deque)
		return (0);
	if (deque->count == 0)
	{
		free(deque);
		return (2);
	}
	temp = deque->frontnode;
	while (temp)
	{
		deque->frontnode = temp->rlink;
		free(temp);
		temp = deque->frontnode;
	}
	deque->count = 0;
	deque->frontnode = NULL;
	deque->rearnode = NULL;
	free(deque);
	return (1);
}

t_LinkedDeque	*copy_deque(t_LinkedDeque *deque)
{
	t_LinkedDeque	*copy;
	t_DequeNode		*temp;
	t_DequeNode		*node;

	copy = create_deque();
	temp = deque->rearnode;
	while (temp)
	{
		node = create_node(temp->data);
		add_front_deque(copy, node);
		temp = temp->flink;
	}
	return (copy);
}

int	deque_size(t_LinkedDeque *deque)
{
	int			n;
	t_DequeNode	*temp;

	n = 0;
	temp = deque->frontnode;
	while (temp)
	{
		temp = temp->rlink;
		n++;
	}
	return (n);
}

int	deque_data(t_LinkedDeque *deque, int idx)
{
	int			index;
	t_DequeNode	*temp;

	temp = deque->frontnode;
	index = 0;
	while (temp)
	{
		if (index == idx)
			break ;
		temp = temp->rlink;
		index++;
	}
	return (temp->idx);
}
