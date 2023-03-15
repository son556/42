/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 23:18:48 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/13 18:35:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

static t_tree	*preset_token_cmd(t_tree *tree)
{
	tree->top = NULL;
	tree->last = NULL;
	tree->cmd.envp_path = NULL;
	tree->cmd.cmd_head = NULL;
	tree->cmd.cmd_arr = NULL;
	tree->export_temp = NULL;
	return (tree);
}

static t_tree	*preset_pipe_heredoc_fd(t_tree *tree)
{
	tree->pipe_cnt = 0;
	tree->here_doc = 0;
	tree->mini_here_doc = 0;
	tree->here_doc_cnt = 0;
	tree->infile = 0;
	tree->outfile = 0;
	tree->child_status = 0;
	tree->heredoc_idx = 0;
	tree->exit_code = 0;
	tree->pipe_fd = NULL;
	tree->here_documets = NULL;
	tree->pid = NULL;
	tree->origin = NULL;
	tree->pure = NULL;
	tree->top = NULL;
	tree->last = NULL;
	return (tree);
}

static t_tree	*preset_envp(t_tree *tree, char **envp)
{
	tree->envp_val = envp_copy(envp);
	tree->env_list = make_env_list(envp);
	tree->export_list = make_export_list(envp);
	tree->env_list = add_env_list(tree->env_list, \
	ft_strcpy("?"), ft_strcpy("0"));
	tree->export_list = add_env_list(tree->export_list, \
	ft_strcpy("?"), ft_strcpy("0"));
	return (tree);
}

t_tree	*tree_preset(char **envp)
{
	t_tree	*tree;

	tree = (t_tree *)malloc(sizeof(t_tree));
	if (!tree)
		ft_error("malloc error\n");
	tree = preset_token_cmd(tree);
	tree = preset_pipe_heredoc_fd(tree);
	tree = preset_envp(tree, envp);
	tree->history = NULL;
	return (tree);
}

t_tree	*tree_set_re(t_tree *tree)
{
	tree = preset_token_cmd(tree);
	tree = preset_pipe_heredoc_fd(tree);
	ft_free_str(tree->envp_val);
	tree->envp_val = env_to_envp(tree->env_list);
	return (tree);
}
