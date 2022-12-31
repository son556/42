#include "../so_long.h"

static void	make_enemy_list2(t_game *g, size_t i, size_t j, size_t idx)
{
	static t_node	*node;

	if (!g->enemy_list->front)
	{
		g->enemy_list->front = new_node_2(j, i, idx);
		node = g->enemy_list->front;
	}
	else
	{
		node->next = new_node_2(j, i, idx);
		node = node->next;
	}
}

void	make_enemy_list(t_game *g)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	i = 0;
	idx = 0;
	g->enemy_list = new_deque();
	while ((g->map)[i])
	{
		j = 0;
		while ((g->map)[i][j] != '\n' && (g->map)[i][j] != 0)
		{
			if ((g->map)[i][j] == '0')
			{
				make_enemy_list2(g, i, j, idx);
				idx++;
				if (idx == 19)
					idx = 0;
			}
			j++;
		}
		i++;
	}
}

void	init_enemy(t_game *g)
{
	t_node			*temp;

	make_enemy_list(g);
	temp = g->enemy_list->front;
	while (temp)
	{
		if (temp->idx == (g->random % 20))
			temp->enemy_alive = 1;
		// if (temp->idx == 3)
		// 	temp->enemy_alive = 1;
		temp = temp->next;
	}
}
