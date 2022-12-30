
#include "../so_long.h"

int	find_enemy(t_game *g)
{
	if (g->user.x + 1 == g->enemy_x && g->user.y == g->enemy_y)
		return (1);
	else if (g->user.x - 1 == g->enemy_x && g->user.y == g->enemy_y)
		return (1);
	else if (g->user.x == g->enemy_x && g->user.y + 1 == g->enemy_y)
		return (1);
	else if (g->user.x == g->enemy_x && g->user.y - 1 == g->enemy_y)
		return (1);
	return (0);
}

void	draw_step_count(t_game *g)
{
	char	*str;

	str = NULL;
	str = ft_itoa(g->user.move);
	mlx_put_image_to_window(g->mlx, g->win, g->custom.n_box, 0, 0);
	mlx_string_put(g->mlx, g->win, 24, 18, 0x000000, str);
	free(str);
}

void	ft_free(int **arr, t_game *g)
{
	int	j;

	j = 0;
	while (j < g->map_v.y_size)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

int	**make_int_map(t_game *g, size_t i, size_t j)
{
	int	**arr;

	arr = (int **)malloc(sizeof(int *) * (g->map_v.y_size));
	while ((g->map)[i])
	{
		arr[i] = (int *)malloc(sizeof(int) * (g->map_v.x_size));
		j = 0;
		while ((g->map)[i][j] != '\n' && (g->map)[i][j] != 0)
		{
			if ((g->map)[i][j] >= '0' && \
				(g->map)[i][j] < '9' && (g->map)[i][j] != '1')
				arr[i][j] = (g->map)[i][j] - '0';
			else if ((g->map)[i][j] == 'C')
				arr[i][j] = -2;
			else if ((g->map)[i][j] == 'E')
				arr[i][j] = -3;
			else if ((g->map)[i][j] == 'P')
				arr[i][j] = -4;
			else if ((g->map)[i][j] == '1')
				arr[i][j] = -1;
			j++;
		}
		i++;
	}
	return (arr);
}

int	check_str(char *str1, char *str2)
{
	int		i;
	int		j;
	int		sign;

	i = -1;
	while (str1[++i])
	{
		if (str1[i] == str2[0])
		{
			j = 0;
			sign = 0;
			while (str1[i + j] && str2[j])
			{
				if (str1[i + j] == str2[j])
					sign = 1;
				else
					sign = 0;
				j++;
			}
			if (str2[j] == '\0' && sign == 1)
				return (1);
		}
	}
	return (0);
}
