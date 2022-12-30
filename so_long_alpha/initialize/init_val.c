#include "../so_long.h"

void	init_start(t_game *game, int *x_width, int *y_width)
{
	*x_width = game->map_v.x_size * 64;
	*y_width = game->map_v.y_size * 64;
	game->user.x = game->user.pre_x * 64;
	game->user.y = game->user.pre_y * 64;
	game->user.pre_x = game->user.x;
	game->user.pre_y = game->user.y;
	game->user.move = 0;
	game->key_sign = 0;
	game->user.d = 3;
}

void	init_custom(t_custom *new)
{
	new->cnt = 0;
	new->x = 0;
	new->y = 0;
}

void	init_map_v(t_map *new)
{
	new->c = 0;
	new->p = 0;
	new->e = 0;
	new->x_size = 0;
	new->y_size = 0;
	new->total_move = 0;
}

void	game_init(t_game *new, char *argv)
{
	new->mlx = 0;
	new->win = 0;
	new->map = 0;
	new->start = 0;
	new->reset = 0;
	new->addr = argv;
	new->key_sign = 0;
	new->random = 0;
	init_map_v(&(new->map_v));
	init_custom(&(new->custom));
}

void	init_enemy(t_game *g)
{
	g->enemy_x = g->random % g->map_v.x_size;
	g->enemy_y = g->random % g->map_v.y_size;
	g->enemy_dir = 0;
	g->enemy_dead = 0;
	while (g->map1[g->enemy_y][g->enemy_x] != 0)
	{
		g->enemy_x++;
		if (g->enemy_x >= g->map_v.x_size - 1)
		{
			g->enemy_x = 0;
			g->enemy_y++;
			if (g->enemy_y >= g->map_v.y_size - 1)
				g->enemy_y = 0;
		}
	}
}
