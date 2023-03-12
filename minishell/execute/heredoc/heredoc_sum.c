/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:54:03 by chanson           #+#    #+#             */
/*   Updated: 2023/03/04 16:36:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	sum_string(char ***temp, t_token *node)
{
	t_token	*tmp_node;
	char	*copy;

	tmp_node = node;
	while (tmp_node)
	{
		copy = ft_strcpy(tmp_node->val);
		*temp = ft_strsjoin(*temp, copy);
		tmp_node = tmp_node->right;
	}
}

void	heredoc_sum(t_token *node, char ***temp)
{
	char	*copy;

	if (node == NULL)
		return ;
	heredoc_sum(node->left, temp);
	if (node->type == TK_STR)
	{
		sum_string(temp, node);
		return ;
	}
	else if (node->type != TK_STR)
	{
		copy = ft_strcpy(node->val);
		*temp = ft_strsjoin(*temp, copy);
	}
	heredoc_sum(node->right, temp);
}
