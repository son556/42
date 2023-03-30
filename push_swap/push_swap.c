/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:45:41 by chanson           #+#    #+#             */
/*   Updated: 2023/03/25 18:11:04 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	determine_input_duplicate(t_LinkedDeque *deque_a)
{
	t_DequeNode	*temp;
	t_DequeNode	*temp_2;

	temp = deque_a->frontnode;
	while (temp->rlink)
	{
		temp_2 = temp->rlink;
		while (temp_2)
		{
			if (temp->data == temp_2->data)
				return (0);
			temp_2 = temp_2->rlink;
		}
		temp = temp->rlink;
	}
	return (1);
}

static int	determine_input_range(t_LinkedDeque *deque_a)
{
	t_DequeNode	*temp;

	temp = deque_a->frontnode;
	while (temp)
	{
		if ((temp->data) > 2147483647 || (temp->data) < -2147483648)
			return (0);
		temp = temp->rlink;
	}
	return (1);
}

static int	determine_input(char **argv, t_LinkedDeque *deque_a)
{
	int		idx;
	int		index;
	char	c;

	index = 1;
	while (argv[index])
	{
		idx = 0;
		while (argv[index][idx])
		{
			c = argv[index][idx];
			if (c == ' ' && idx != 0 && argv[index][idx + 1] != '\0')
				idx++;
			if (c == '-' || c == '+')
				idx++;
			if (ft_isdigit(argv[index][idx++]) == 0)
				return (0);
		}
		index++;
	}
	if (determine_input_range(deque_a) == 0)
		return (0);
	if (determine_input_duplicate(deque_a) == 0)
		return (0);
	return (1);
}

static void	make_d_a(t_LinkedDeque *deque_a, t_DequeNode **node, char **argv)
{
	int				idx;
	int				index;
	char			**temp;
	long long		num;

	idx = 1;
	while (argv[idx])
	{
		temp = ft_split(argv[idx], ' ');
		index = 0;
		while (temp[index])
		{
			num = ft_aatoi(temp[index]);
			*node = create_node(num);
			add_rear_deque(deque_a, *node);
			index++;
		}
		ft_free(temp);
		idx++;
	}
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_LinkedDeque	*deque_a;
	t_LinkedDeque	*deque_b;
	t_DequeNode		*node;
	size_t			i;

	i = 1;
	if (argc <= 1)
		return (0);
	if (!check_argv(argc, argv))
		return (0);
	deque_a = create_deque();
	deque_b = create_deque();
	node = NULL;
	while (argv[i])
	{
		printf("%s ", argv[i]);
		i++;
	}
	make_d_a(deque_a, &node, argv);
	if (!determine_input(argv, deque_a))
	{
		ft_printf("Error\n");
		delete_deque(deque_a);
		delete_deque(deque_b);
		return (0);
	}
	if (sort_check_asc(deque_a) || deque_size(deque_a) == 1)
		return (0);
	init_algorithm(deque_a, deque_b);
	delete_deque(deque_a);
	delete_deque(deque_b);
	return (0);
}
