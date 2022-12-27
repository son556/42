/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_user.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:36:02 by chanson           #+#    #+#             */
/*   Updated: 2022/12/26 18:10:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*dir_img(t_game *g, int d)
{
	if (d == 0)
		return (g->user.user_e0);
	if (d == 1)
		return (g->user.user_w0);
	if (d == 2)
		return (g->user.user_n0);
	return (g->user.user_s0);
}

void	draw_move_e(t_game *g)
{
	int	x;
	int	y;

	x = (g->user.x) / 64;
	y = (g->user.y) / 64;
	x++;
	if (x < g->map.x_size - 1 && (g->arr)[y][x] != -1)
	{
		g->key_sign = 1;
		g->user.x += 64;
		g->user.d = 0;
		g->user.move++;
		draw_user(g);
	}
}

void	draw_move_w(t_game *g)
{
	int	x;
	int	y;

	x = (g->user.x) / 64;
	y = (g->user.y) / 64;
	x--;
	if (x > 0 && (g->arr)[y][x] != -1)
	{
		g->key_sign = 1;
		g->user.x -= 64;
		g->user.d = 1;
		g->user.move++;
		draw_user(g);
	}
}

void	draw_move_n(t_game *g)
{
	int	x;
	int	y;

	x = (g->user.x) / 64;
	y = (g->user.y) / 64;
	y--;
	if (y > 0 && (g->arr)[y][x] != -1)
	{
		g->key_sign = 1;
		g->user.y -= 64;
		g->user.d = 2;
		g->user.move++;
		draw_user(g);
	}
}

void	draw_move_s(t_game *g)
{
	int	x;
	int	y;

	x = (g->user.x) / 64;
	y = (g->user.y) / 64;
	y++;
	if (y < g->map.y_size - 1 && (g->arr)[y][x] != -1)
	{
		g->key_sign = 1;
		g->user.y += 64;
		g->user.d = 3;
		g->user.move++;
		draw_user(g);
	}
}
