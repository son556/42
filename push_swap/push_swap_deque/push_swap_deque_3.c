/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_deque_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 02:25:30 by chanson           #+#    #+#             */
/*   Updated: 2022/12/16 21:59:54 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_DequeNode	*create_node_idx(long long data, int idx)
{
	t_DequeNode	*node;

	node = (t_DequeNode *)malloc(sizeof(t_DequeNode));
	if (!node)
		return (0);
	node->data = data;
	node->idx = idx;
	node->flink = NULL;
	node->rlink = NULL;
	return (node);
}

int	check_argv(int argc, char **argv)
{
	int	index;
	int	n;

	index = 1;
	while (index < argc - 1)
	{
		n = argv[index][0];
		if (n == 0 || (int)argv[1][0] == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		index++;
	}
	return (1);
}
