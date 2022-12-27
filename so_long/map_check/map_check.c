/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:53:07 by chanson           #+#    #+#             */
/*   Updated: 2022/12/24 20:40:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	map_1(char *line, int idx, t_game *g)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (idx == 0 || idx == g->map.y_size - 1)
		{
			if (line[i] != '1' && line[i] != '\n')
				return (0);
		}
		else
		{
			if (i == 0 && line[i] != '1')
				return (0);
			if (i == g->map.x_size - 1 && line[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static void	map_check_1(t_game *g, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			g->map.c++;
		if (line[i] == 'P')
			g->map.p++;
		if (line[i] == 'E')
			g->map.e++;
		i++;
	}
}

int	map_check(int fd, t_game *g)
{
	char	*line;
	int		n;
	int		idx;

	line = get_next_line(fd);
	idx = 0;
	while (line)
	{
		n = ft_strllen(line);
		map_check_1(g, line);
		if (line[n - 1] == '\n')
			n--;
		if (!map_1(line, idx, g) || (g->map.x_size) != n)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
		idx++;
	}
	if (g->map.c < 1 || g->map.e != 1 || g->map.p != 1)
		idx = 0;
	close(fd);
	return (idx);
}

void	make_map(t_game *g, int **arr, int fd)
{
	char	*line;
	int		i;
	int		index;

	index = -1;
	while (index++ < g->map.y_size - 1)
	{
		i = -1;
		line = get_next_line(fd);
		while (i++ < g->map.x_size - 1)
		{
			if (line[i] >= '0' && line[i] < '9' && line[i] != '1')
				arr[index][i] = line[i] - '0';
			else if (line[i] == 'C')
				arr[index][i] = -2;
			else if (line[i] == 'E')
				arr[index][i] = -3;
			else if (line[i] == 'P')
				arr[index][i] = -4;
			else if (line[i] == '1')
				arr[index][i] = -1;
		}
		free(line);
	}
	close(fd);
}

void	map_size(int fd, t_game *game)
{
	char	*line;

	game->map.p = 0;
	game->map.e = 0;
	game->map.c = 0;
	line = get_next_line(fd);
	game->map.x_size = ft_strllen(line) - 1;
	game->map.y_size = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		game->map.y_size++;
	}
	close(fd);
}
