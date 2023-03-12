/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:41:09 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	find_top(t_list *list)
{
	int		i;
	int		type;
	int		index;
	t_token	*temp;

	i = 0;
	index = -1;
	temp = list->first;
	type = temp->type;
	while (temp)
	{
		if (type <= (int)(temp->type) && temp->type != TK_STR)
		{
			if (temp->type >= TK_IRD && temp->type <= TK_ARD)
				type = 1;
			if (temp->type == TK_PIPE)
				type = 5;
			if (temp->type == TK_AND || temp->type == TK_OR)
				type = 6;
			index = i;
		}
		temp = temp->right;
		i++;
	}
	return (index);
}

static void	link_tree(t_tree *tree, t_token *temp, int d, t_token **pre)
{
	if (tree->top == NULL)
	{
		tree->top = temp;
		tree->last = temp;
	}
	else if (d == 1)
	{
		tree->last->left = temp;
		tree->last = temp;
	}
	else
	{
		(*pre)->right = temp;
		tree->last = temp;
	}
}

static void	link_tree_last(t_list *list, t_tree *tree, int d, t_token **pre)
{
	t_token	*temp;

	temp = list->first;
	while (temp->left)
		temp = temp->left;
	if (d == 1)
		tree->last->left = temp;
	else
		(*pre)->right = temp;
}

t_token	*add_node(t_list *list, t_tree *tree, int d, t_token **pre)
{
	int		i;
	int		idx;
	t_token	*temp;

	idx = find_top(list);
	if (tree->top == NULL && idx == -1)
	{
		tree->top = list->first;
		return (FALSE);
	}
	if (idx == -1)
	{
		link_tree_last(list, tree, d, pre);
		return (FALSE);
	}
	temp = list->first;
	i = 0;
	while (i++ < idx)
		temp = temp->right;
	link_tree(tree, temp, d, pre);
	if (temp->left == NULL)
		list->first = NULL;
	else if (temp->left->right != NULL)
		temp->left->right = NULL;
	return (temp);
}
