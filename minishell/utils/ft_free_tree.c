/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:34:25 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 18:11:58 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	ft_free_int(int **arr, t_tree *tree)
{
	int	i;

	i = 0;
	while (i < tree->pipe_cnt)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	ft_free_tk_list(t_token *node)
{
	t_token	*temp;
	t_token	*gar;

	temp = node;
	while (temp->left != NULL)
		temp = temp->left;
	while (temp)
	{
		gar = temp;
		temp = temp->right;
		free(gar->val);
		free(gar);
	}
}

static void	_ft_free_tree(t_token *node)
{
	if (node == NULL)
		return ;
	if (node->type == TK_STR)
	{
		ft_free_tk_list(node);
		return ;
	}
	_ft_free_tree(node->left);
	free(node->val);
	free(node);
	_ft_free_tree(node->right);
}

void	ft_free_tree(t_tree *tree)
{
	ft_free_str(tree->here_documets);
	ft_free_str(tree->cmd.cmd_arr);
	ft_free_str(tree->cmd.envp_path);
	ft_free_str(tree->echo_export_arr);
	ft_free_str(tree->pure);
	ft_free_str(tree->export_temp);
	free(tree->cmd.cmd_head);
	free(tree->pid);
	ft_free_int(tree->pipe_fd, tree);
	_ft_free_tree(tree->top);
}
