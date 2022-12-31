#include "../so_long.h"

static void	dir_enemy(t_game *g, t_node *temp, int x, int y);

static void	enemy_deque_back(t_game *g, t_node *temp, int x, int y)
{
	int	i;
	int	j;

	i = g->user.x / 64;
	j = g->user.y / 64;
	if ((temp->map)[j][i] != 0)
		return ;
	deque_back(temp->way, x, y);
}

static void	dir_enemy2(t_game *g, t_node *temp, int x, int y)
{
	if (y + 1 < g->map_v.y_size && (temp->map)[y + 1][x] == 0)
	{
		(temp->map)[y + 1][x] = (temp->map)[y][x] + 1;
		enemy_deque_back(g, temp, x, y + 1);
		dir_enemy(g, temp, x, y + 1);
	}
	if (y - 1 > 0 && (temp->map)[y - 1][x] == 0)
	{
		(temp->map)[y - 1][x] = (temp->map)[y][x] + 1;
		enemy_deque_back(g, temp, x, y - 1);
		dir_enemy(g, temp, x, y - 1);
	}
	if (x + 1 < g->map_v.x_size && (temp->map)[y][x + 1] == 0)
	{
		(temp->map)[y][x + 1] = (temp->map)[y][x] + 1;
		enemy_deque_back(g, temp, x + 1, y);
		dir_enemy(g, temp, x + 1, y);
	}
	if (x - 1 > 0 && (temp->map)[y][x - 1] == 0)
	{
		(temp->map)[y][x - 1] = (temp->map)[y][x] + 1;
		enemy_deque_back(g, temp, x - 1, y);
		dir_enemy(g, temp, x - 1, y);
	}
}

static void	dir_enemy(t_game *g, t_node *temp, int x, int y)
{
	int	user_x;
	int	user_y;

	user_x = (g->user.x) / 64;
	user_y = (g->user.y) / 64;
	if (x == (g->user.x / 64) && y == (g->user.y / 64))
	{
		deque_back(temp->way, x, y);
		return ;
	}
	if ((temp->map)[user_y][user_x] == 0)
		dir_enemy2(g, temp, x, y);
	if ((temp->map)[user_y][user_x] == 0)
		delete_back_deque(temp->way);
}

static void	move_enemy(t_game *g, t_node *temp)
{
	int	x;
	int	y;

	if (temp->way == 0 || temp->way->cnt == 0)
	{
		ft_free(temp->map, g);
		delete_deque(temp->way);
		temp->map = dup_arr(g->map1, g->map_v.x_size, g->map_v.y_size);
		make_enemy_map(temp->map, g);
		temp->way = new_deque();
		deque_back(temp->way, temp->x, temp->y);
		(temp->map)[temp->y][temp->x] = 1;
		dir_enemy(g, temp, temp->x, temp->y);
	}
	x = temp->way->front->x;
	y = temp->way->front->y;
	temp->x = x;
	temp->y = y;
	put_image_to_window(g, temp->x * 64, temp->y * 64, g->custom.enemy);
	delete_front_deque(temp->way);
}

void	draw_enemy(t_game *g)
{
	static size_t	time;
	t_node			*temp;

	time++;
	temp = g->enemy_list->front;
	while (temp)
	{
		if (temp->enemy_alive == 1)
		{
			put_image_to_window(g, temp->x * 64, temp->y * 64, g->custom.enemy);
			if (time % 50 == 0)
			{
				move_enemy(g, temp);
				if (time == 1600)
					time = 0;
			}
		}
		temp = temp->next;
	}
}
