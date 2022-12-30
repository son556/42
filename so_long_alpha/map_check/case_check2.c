#include "../so_long.h"

// void	put_game_end_img(t_game *g)
// {
// 	mlx_clear_window(g->mlx, g->win);
// 	g->key_sign = 0;
// 	g->reset = 1;
// 	mlx_put_image_to_window(g->mlx, g->win, g->end_img, 0, 0);
// }

void	put_game_over_img(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	g->key_sign = 0;
	g->reset = 1;
	mlx_put_image_to_window(g->mlx, g->win, g->game_over, 0, 0);
}

void	find_site(int **arr, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->custom.cnt = 0;
	while (y < game->map_v.y_size)
	{
		x = -1;
		while (x++ < game->map_v.x_size - 1)
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
		}
		y++;
	}
}
