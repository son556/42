/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 19:19:47 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 21:53:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	press_key(int key_code, t_game *g)
{
	int	x;
	int	y;

	x = g->user.x / 64;
	y = g->user.y / 64;
	if (key_code == KEY_ESC)
		exit(0);
	if (g->reset == 1 && key_code == 15)
		game_restart(g);
	else if (g->key_sign)
		draw_user(g);
	else if (key_code == KEY_D && x < g->map.x_size - 1 && !(g->reset))
		draw_move_e(g);
	else if (key_code == KEY_A && x > 0 && !(g->reset))
		draw_move_w(g);
	else if (key_code == KEY_S && y < g->map.y_size - 1 && !(g->reset))
		draw_move_s(g);
	else if (key_code == KEY_W && y > 0 && !(g->reset))
		draw_move_n(g);
	return (1);
}

void	put_image_to_window(t_game *g, int x, int y, void *image)
{
	mlx_put_image_to_window(g->mlx, g->win, image, x, y);
}

static void	_draw_user_x(t_game *g)
{
	int			s;
	static int	cnt;

	s = g->user.pre_x;
	if (g->user.pre_x < g->user.x)
	{
		if (cnt % 4 == 0)
			put_image_to_window(g, s, g->user.y, g->user.user_e1);
		else
			put_image_to_window(g, s, g->user.y, g->user.user_e2);
		g->user.pre_x += 4;
	}
	if (g->user.pre_x > g->user.x)
	{
		if (cnt % 4 == 0)
			put_image_to_window(g, s, g->user.y, g->user.user_w1);
		else
			put_image_to_window(g, s, g->user.y, g->user.user_w2);
		g->user.pre_x -= 4;
	}
	if (cnt++ == 15)
	{
		cnt = 0;
		g->key_sign = 0;
	}
}

static void	_draw_user_y(t_game *g)
{
	int			s;
	static int	cnt_2;

	s = g->user.pre_y;
	if (g->user.pre_y < g->user.y)
	{
		if (cnt_2 % 4 == 0)
			put_image_to_window(g, g->user.x, s, g->user.user_s1);
		else
			put_image_to_window(g, g->user.x, s, g->user.user_s2);
		g->user.pre_y += 4;
	}
	if (g->user.pre_y > g->user.y)
	{
		if (cnt_2 % 4 == 0)
			put_image_to_window(g, g->user.x, s, g->user.user_n1);
		else
			put_image_to_window(g, g->user.x, s, g->user.user_n2);
		g->user.pre_y -= 4;
	}
	if (cnt_2++ == 15)
	{
		cnt_2 = 0;
		g->key_sign = 0;
	}
}

void	draw_user(t_game *g)
{
	int	x;
	int	y;

	x = g->user.pre_x;
	y = g->user.pre_y;
	if (x == g->user.x && y == g->user.y)
		put_image_to_window(g, x, y, dir_img(g, g->user.d));
	else
	{
		if (x != g->user.x)
			_draw_user_x(g);
		else
			_draw_user_y(g);
	}
}
