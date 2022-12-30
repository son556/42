#include "../so_long.h"

void	draw_start(t_game *g)
{
	static int	random;
	char		*line;

	line = "Press enter!!";
	g->random = random;
	mlx_clear_window(g->mlx, g->win);
	if (g->start == 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->game_start, 0, 0);
		mlx_string_put(g->mlx, g->win, 500, 64, 0xFFFFFF, line);
	}
	else
	{
		line = "Press enter to start the next step";
		mlx_string_put(g->mlx, g->win, 500, 64, 0xFFFFFF, line);
	}
	random++;
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
	mlx_clear_window(g->mlx, g->win);
	while (y < g->map_v.y_size)
	{
		x = 0;
		while (x < g->map_v.x_size)
		{
			if ((g->map1)[y][x] == -1)
				_draw_map(g, -1, x, y);
			else if ((g->map1)[y][x] == -2)
				_draw_map(g, -2, x, y);
			else if ((g->map1)[y][x] == -3)
				_draw_map(g, -3, x, y);
			else if ((g->map1)[y][x] == -4)
				_draw_map(g, -4, x, y);
			else
				_draw_map(g, 0, x, y);
			x++;
		}
		y++;
	}
}
