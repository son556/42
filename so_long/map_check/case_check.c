/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:03:08 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 15:41:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	game_restart(t_game *g)
{
	int		fd;

	fd = open(g->addr, O_RDONLY);
	make_map(g, g->arr, fd);
	find_site(g->arr, g);
	g->map.total_move = (g->arr_2)[g->custom.y][g->custom.x];
	g->reset = 0;
	g->user.x = g->user.x * 64;
	g->user.y = g->user.y * 64;
	g->user.pre_x = g->user.x;
	g->user.pre_y = g->user.y;
	g->user.move = 0;
	g->key_sign = 0;
	g->user.d = 3;
	return (0);
}

static void	put_game_over_img(t_game *g)
{
	int	x;
	int	y;

	x = ((g->user.x) * 64) / 2 - 2;
	y = ((g->user.y) * 64) / 2 - 2;
	mlx_clear_window(g->mlx, g->win);
	g->key_sign = 0;
	g->reset = 1;
	mlx_put_image_to_window(g->mlx, g->win, g->game_over, 0, 0);
}

void	case_check(t_game *g)
{
	int	x;
	int	y;

	x = g->user.x / 64;
	y = g->user.y / 64;
	if ((g->arr)[y][x] == -2)
	{
		g->map.total_move += 3;
		g->custom.cnt--;
		(g->arr)[y][x] = 0;
	}
	if ((g->arr)[y][x] == -3 && g->custom.cnt == 0)
	{
		x = ((g->user.x) * 64) / 2 - 2;
		y = ((g->user.y) * 64) / 2 - 2;
		mlx_clear_window(g->mlx, g->win);
		g->key_sign = 0;
		g->reset = 1;
		mlx_put_image_to_window(g->mlx, g->win, g->end_img, 0, 0);
	}
	if (g->user.move > g->map.total_move + 10)
		put_game_over_img(g);
}
