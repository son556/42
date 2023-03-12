/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_cnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:24:30 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	_cnt_heredoc_par(char *str, t_tree *tree)
{
	char	**temp;
	int		i;
	char	*temp_str;

	temp_str = ft_strtrim_couple_check(str, '(', ')');
	if (temp_str[0] == '(')
	{
		free(temp_str);
		return ;
	}
	i = 0;
	temp = ft_split(temp_str);
	while (temp[i])
	{
		if (ft_strscmp(temp[i], "<<") == TRUE)
			tree->here_doc_cnt++;
		i++;
	}
	ft_free_str(temp);
	free(temp_str);
}

void	cnt_heredoc(t_token *node, t_tree *tree)
{
	if (node == NULL || node->type == TK_STR)
	{
		if (node != NULL && node->val[0] == '(')
			_cnt_heredoc_par(node->val, tree);
		return ;
	}
	if (node->type == TK_HRD)
		tree->here_doc_cnt++;
	cnt_heredoc(node->left, tree);
	cnt_heredoc(node->right, tree);
}
