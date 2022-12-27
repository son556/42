/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:51:20 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 22:08:58 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main_loop(t_game *g)
{
	if (g->reset == 0 && g->start == 1)
	{
		draw_map(g);
		draw_user(g);
		case_check(g);
	}
	else if (g->reset && g->start)
	{
		mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &press_key, g);
		mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &close_game, g);
	}
	return (0);
}

void	game_start(int fd, char *str, t_game *game)
{
	void	*win;
	int		x_width;
	int		y_width;

	if (fd == 0 || !str)
		return ;
	x_width = game->map.x_size * 64;
	y_width = game->map.y_size * 64;
	game->user.x = game->user.pre_x * 64;
	game->user.y = game->user.pre_y * 64;
	game->user.pre_x = game->user.x;
	game->user.pre_y = game->user.y;
	game->user.move = 0;
	game->key_sign = 0;
	game->user.d = 3;
	game->mlx = mlx_init();
	make_user(game, game->mlx);
	make_custom(game, game->mlx);
	win = mlx_new_window(game->mlx, x_width, y_width, "g");
	game->win = win;
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &close_game, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

void	dup_arr(int **arr, int **arr2, int size_x, int size_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < size_y)
	{
		x = 0;
		while (x < size_x)
		{
			arr2[y][x] = arr[y][x];
			x++;
		}
		y++;
	}
}

int	main_2(t_game *game, char *str)
{
	int	**arr;
	int	fd;

	arr = (int **)malloc(sizeof(int *) * (game->map.y_size));
	fd = 0;
	while (fd < game->map.y_size)
		arr[fd++] = (int *)malloc(sizeof(int) * (game->map.x_size));
	fd = open(str, O_RDONLY);
	make_map(game, arr, fd);
	game->arr = (int **)malloc(sizeof(int *) * (game->map.y_size));
	fd = 0;
	while (fd < game->map.y_size)
		(game->arr)[fd++] = (int *)malloc(sizeof(int) * (game->map.x_size));
	dup_arr(arr, game->arr, game->map.x_size, game->map.y_size);
	fd = map_site(arr, game);
	if (fd == 0)
	{
		write(0, "error: map is shit\n", 19);
		exit (0);
	}
	game->arr_2 = arr;
	game_start(fd, str, game);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*game;

	if (argc != 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("file error");
		return (0);
	}
	map_size(fd, game);
	fd = open(argv[1], O_RDONLY);
	if (!map_check(fd, game))
	{
		free(game);
		write(0, "map_check error!!\n", 18);
		return (2);
	}
	game->addr = argv[1];
	game->reset = 0;
	game->start = 0;
	main_2(game, argv[1]);
}
