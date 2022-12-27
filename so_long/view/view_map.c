/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:03:38 by chanson           #+#    #+#             */
/*   Updated: 2022/12/26 21:35:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	*file_to_image(void *mlx, char *addr)
{
	int		w;
	int		h;
	void	*result;

	result = mlx_xpm_file_to_image(mlx, addr, &w, &h);
	return (result);
}

void	make_user(t_game *g, void *mlx)
{
	g->user.user_e0 = file_to_image(mlx, "./asset/player_E00.xpm");
	g->user.user_e1 = file_to_image(mlx, "./asset/player_E01.xpm");
	g->user.user_e2 = file_to_image(mlx, "./asset/player_E02.xpm");
	g->user.user_w0 = file_to_image(mlx, "./asset/player_W00.xpm");
	g->user.user_w1 = file_to_image(mlx, "./asset/player_W01.xpm");
	g->user.user_w2 = file_to_image(mlx, "./asset/player_W02.xpm");
	g->user.user_s0 = file_to_image(mlx, "./asset/player_S00.xpm");
	g->user.user_s1 = file_to_image(mlx, "./asset/player_S01.xpm");
	g->user.user_s2 = file_to_image(mlx, "./asset/player_S02.xpm");
	g->user.user_n0 = file_to_image(mlx, "./asset/player_N00.xpm");
	g->user.user_n1 = file_to_image(mlx, "./asset/player_N01.xpm");
	g->user.user_n2 = file_to_image(mlx, "./asset/player_N02.xpm");
}

void	make_custom(t_game *g, void *mlx)
{
	int	w;
	int	h;

	g->custom.ball = mlx_xpm_file_to_image(mlx, "./asset/ball.xpm", &w, &h);
	g->custom.tile0 = mlx_xpm_file_to_image(mlx, "./asset/tile00.xpm", &w, &h);
	g->custom.tile1 = mlx_xpm_file_to_image(mlx, "./asset/tile01.xpm", &w, &h);
	g->custom.ladder = mlx_xpm_file_to_image(mlx, "./asset/ladder.xpm", &w, &h);
	g->game_over = mlx_xpm_file_to_image(mlx, "./asset/gameover.xpm", &w, &h);
	g->end_img = mlx_xpm_file_to_image(mlx, "./asset/ending.xpm", &w, &h);
}

void static	_draw_map(t_game *g, int cha, int x, int y)
{
	void	*mlx;
	void	*win;

	mlx = g->mlx;
	win = g->win;
	if (cha == -1)
		mlx_put_image_to_window(mlx, win, g->custom.tile1, x * 64, y * 64);
	else if (cha == 0 || cha == -4)
		mlx_put_image_to_window(mlx, win, g->custom.tile0, x * 64, y * 64);
	else if (cha == -2)
	{
		mlx_put_image_to_window(mlx, win, g->custom.tile0, x * 64, y * 64);
		mlx_put_image_to_window(mlx, win, g->custom.ball, x * 64, y * 64);
	}
	else if (cha == -3)
		mlx_put_image_to_window(mlx, win, g->custom.ladder, x * 64, y * 64);
}

void	draw_map(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.y_size)
	{
		x = 0;
		while (x < g->map.x_size)
		{
			if ((g->arr)[y][x] == -1)
				_draw_map(g, -1, x, y);
			else if ((g->arr)[y][x] == -2)
				_draw_map(g, -2, x, y);
			else if ((g->arr)[y][x] == -3)
				_draw_map(g, -3, x, y);
			else if ((g->arr)[y][x] == -4)
				_draw_map(g, -4, x, y);
			else
				_draw_map(g, 0, x, y);
			x++;
		}
		y++;
	}
}
