/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:58:03 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	_make_node_val(t_token *node, char **str_arr, char *str)
{
	int		i;

	i = -1;
	free(str);
	str = NULL;
	str = ft_strcjoin(str, '(');
	while (str_arr[++i])
	{
		str = ft_strstr(str, str_arr[i]);
		if (str_arr[i + 1] != NULL)
			str = ft_strcjoin(str, ' ');
	}
	str = ft_strcjoin(str, ')');
	node->val = ft_str_change(node->val, str);
	free(str);
	ft_free_str(str_arr);
}

void	mini_heredoc(t_token *node, t_tree *tree)
{
	char	*str;
	char	**str_arr;
	int		i;
	int		idx;

	tree->mini_here_doc = 0;
	str = ft_strtrim_couple_check(node->val, '(', ')');
	str_arr = ft_split(str);
	i = -1;
	while (str_arr[++i])
	{
		if (ft_strscmp(str_arr[i], "<<") == TRUE)
		{
			str_arr[i] = ft_str_change(str_arr[i], "<");
			tree->mini_here_doc++;
		}
		else if (tree->mini_here_doc > 0)
		{
			tree->mini_here_doc--;
			idx = ft_heredoc(tree, str_arr[i]);
			str_arr[i] = ft_str_change(str_arr[i], \
				tree->here_documets[idx - 1]);
		}
	}
	_make_node_val(node, str_arr, str);
}
