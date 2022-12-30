#include "../so_long.h"

static void	dir_enemy(t_game *g)
{
	if (g->enemy_dir == 0)
	{
		if (g->map[g->enemy_y][g->enemy_x + 1] == '1')
			g->enemy_dir = 1;
		else
			g->enemy_x++;
	}
	if (g->enemy_dir == 1)
	{
		if (g->map[g->enemy_y + 1][g->enemy_x] == '1')
			g->enemy_dir = 2;
		else
			g->enemy_y++;
	}
	if (g->enemy_dir == 2)
	{
		if (g->map[g->enemy_y][g->enemy_x - 1] == '1')
			g->enemy_dir = 3;
		else
			g->enemy_x--;
	}
	if (g->enemy_dir == 3)
	{
		if (g->map[g->enemy_y - 1][g->enemy_x] == '1')
			g->enemy_dir = 0;
		else
			g->enemy_y--;
	}
}

static void	move_enemy(t_game *g, size_t time)
{
	if (time == 300)
		g->enemy_dir = 3;
	if (time == 800)
		g->enemy_dir = 1;
	if (time == 1000)
		g->enemy_dir = 2;
	if (time == 1500)
		g->enemy_dir = 0;
	dir_enemy(g);
	put_image_to_window(g, g->enemy_x * 64, g->enemy_y * 64, g->custom.enemy);
}

void	draw_enemy(t_game *g)
{
	static size_t	time;

	time++;
	if (g->enemy_dead == 0)
	{
		put_image_to_window(g, g->enemy_x * 64, g->enemy_y * 64, \
												g->custom.enemy);
		if (time % 100 == 0)
		{
			move_enemy(g, time);
			if (time == 1600)
				time = 0;
		}
	}
}

void	draw_catch(t_game *g)
{
	g->enemy_dead = 1;
}
