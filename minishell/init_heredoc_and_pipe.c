/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc_and_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:29:59 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/11 18:16:28 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static void	start_cmd(t_tree *tree, char **temp)
{
	if (tree->pipe_cnt > 0)
		execute_pipe(temp, tree);
	else
		execute_no_pipe(temp, tree);
}

static t_tree	*init_heredoc(t_tree *tree, char ***temp)
{
	int	i;

	cnt_heredoc(tree->top, tree);
	tree->here_documets = (char **)malloc(sizeof(char *) * \
		(tree->here_doc_cnt + 1));
	if (!tree->here_documets)
		ft_error("malloc error\n");
	i = -1;
	while (++i < tree->here_doc_cnt + 1)
		tree->here_documets[i] = NULL;
	execute_heredoc(tree->top, tree, 's');
	ft_free_str(*temp);
	*temp = NULL;
	heredoc_sum(tree->top, temp);
	return (tree);
}

void	_init_heredoc_and_pipe(t_tree *tree, char ***temp, char *str)
{
	tree = init_heredoc(tree, temp);
	tree->pipe_cnt = count_pipe(*temp);
	tree->echo_export_arr = builtin_split(str);
	start_cmd(tree, *temp);
	unlink_heredoc(tree);
	ft_free_tree(tree);
	ft_free_str(*temp);
	*temp = NULL;
	free(str);
	str = NULL;
}
