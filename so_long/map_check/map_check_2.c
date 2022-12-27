/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:55:42 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 15:35:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	make_site(int **arr, t_game *game, int x, int y)
{
	game->custom.cnt = 0;
	while (y++ < game->map.y_size - 1)
	{
		x = -1;
		while (x++ < game->map.x_size - 1)
		{
			if (arr[y][x] == -3)
			{
				game->custom.x = x;
				game->custom.y = y;
			}
			else if (arr[y][x] == -4)
			{
				game->user.x = x;
				game->user.y = y;
			}
			if (arr[y][x] == -2)
				game->custom.cnt++;
			if (arr[y][x] != -1)
				arr[y][x] = 0;
		}
	}
}

static void	ft_case(int **arr, t_game *g, t_deque *deque, int c)
{
	int	x;
	int	y;

	x = g->user.x;
	y = g->user.y;
	if (c == 1)
	{
		arr[y][x + 1] = arr[y][x] + 1;
		deque_back(deque, x + 1, y);
	}
	if (c == 2)
	{
		arr[y][x - 1] = arr[y][x] + 1;
		deque_back(deque, x - 1, y);
	}
	if (c == 3)
	{
		arr[y + 1][x] = arr[y][x] + 1;
		deque_back(deque, x, y + 1);
	}
	if (c == 4)
	{
		arr[y - 1][x] = arr[y][x] + 1;
		deque_back(deque, x, y - 1);
	}
}

static void	map_way_check(int **arr, t_game *g)
{
	t_node	*node;
	t_deque	*deque;

	g->user.pre_x = g->user.x;
	g->user.pre_y = g->user.y;
	node = new_node(g->user.x, g->user.y);
	deque = new_deque();
	deque_add_back(deque, node);
	while (deque->cnt)
	{
		g->user.x = deque->front->x;
		g->user.y = deque->front->y;
		if (g->user.x + 1 < g->map.x_size && arr[g->user.y][g->user.x + 1] == 0)
			ft_case(arr, g, deque, 1);
		if (g->user.x - 1 >= 0 && arr[g->user.y][g->user.x - 1] == 0)
			ft_case(arr, g, deque, 2);
		if (g->user.y + 1 < g->map.y_size && arr[g->user.y + 1][g->user.x] == 0)
			ft_case(arr, g, deque, 3);
		if (g->user.y - 1 >= 0 && arr[g->user.y - 1][g->user.x] == 0)
			ft_case(arr, g, deque, 4);
		delete_front_deque(deque);
	}
	delete_deque(deque);
}

int	map_site(int **arr, t_game *g)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	make_site(arr, g, x, y);
	map_way_check(arr, g);
	if (arr[g->custom.y][g->custom.x] == 0)
		return (0);
	g->map.total_move = arr[g->custom.y][g->custom.x];
	return (1);
}

// void	display_arr(int **arr, t_site *site)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < site->y_size)
// 	{
// 		x = 0;
// 		while (x < site->x_size)
// 		{
// 			printf("%d ", arr[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	printf("\n");
// }
