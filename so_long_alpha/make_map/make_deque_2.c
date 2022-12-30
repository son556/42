#include "../so_long.h"

void	deque_back(t_deque *deque, int x, int y)
{
	t_node	*temp;

	temp = new_node(x, y);
	deque_add_back(deque, temp);
}

t_node	*new_node_2(int x, int y, int idx)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->x = x;
	node->y = y;
	node->idx = idx;
	node->next = NULL;
	return (node);
}
