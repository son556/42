/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:03:10 by chanson           #+#    #+#             */
/*   Updated: 2022/12/15 17:01:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_LinkedDeque	*create_deque(void)
{
	t_LinkedDeque	*deque;

	deque = (t_LinkedDeque *)malloc(sizeof(t_LinkedDeque));
	if (!deque)
		return (0);
	deque->count = 0;
	deque->frontnode = NULL;
	deque->rearnode = NULL;
	return (deque);
}

t_DequeNode	*create_node(long long num)
{
	t_DequeNode	*node;

	node = (t_DequeNode *)malloc(sizeof(t_DequeNode));
	if (!node)
		return (0);
	node->data = num;
	node->flink = NULL;
	node->rlink = NULL;
	return (node);
}

int	add_front_deque(t_LinkedDeque *deque, t_DequeNode *node)
{
	if (!deque || !node)
		return (0);
	if (deque->count == 0)
	{
		deque->frontnode = node;
		deque->rearnode = node;
		deque->count++;
		node->flink = NULL;
		node->rlink = NULL;
	}
	else
	{
		node->flink = NULL;
		node->rlink = deque->frontnode;
		deque->frontnode->flink = node;
		deque->frontnode = node;
		deque->count++;
	}
	return (1);
}

int	add_rear_deque(t_LinkedDeque *deque, t_DequeNode *node)
{
	if (!deque || !node)
		return (0);
	if (deque -> count == 0)
	{
		deque->frontnode = node;
		deque->rearnode = node;
		deque->count++;
		node->flink = NULL;
		node->rlink = NULL;
	}
	else
	{
		node->flink = deque->rearnode;
		node->rlink = NULL;
		deque->rearnode->rlink = node;
		deque->rearnode = node;
		deque->count++;
	}
	return (1);
}

int	delete_front(t_LinkedDeque *deque)
{
	t_DequeNode	*temp;

	if (!deque)
		return (0);
	if (deque->count > 1)
	{
		temp = deque->frontnode;
		deque->frontnode = temp->rlink;
		deque->frontnode->flink = NULL;
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
