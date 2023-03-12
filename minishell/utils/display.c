/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:48:49 by chanson           #+#    #+#             */
/*   Updated: 2023/03/09 19:34:10 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	show_list(t_list	*list)
{
	t_token	*temp;
	int		i;

	if (!list)
	{
		printf("%s\n", NULL);
		return ;
	}
	temp = list->first;
	i = 0;
	printf("------------------display list------------------------\n\n");
	while (temp)
	{
		printf("list[%d]: %s	type: %d\n", i, temp->val, temp->type);
		i++;
		temp = temp->right;
	}
	printf("---------------------end------------------------------\n\n");
}

void	show_node_list(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		printf("%s ", temp->val);
		temp = temp->right;
	}
	printf("\n");
}

void	display_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		printf("arr is NULL\n");
		return ;
	}
	while (1)
	{
		printf("str[%d]: %s\n", i, str[i]);
		if (str[i] == NULL)
			break ;
		i++;
	}
}

void	display_tree(t_token *root, char c)
{
	if (root == NULL)
		return ;
	if (root->type != TK_STR)
	{
		printf("%c: ", c);
		printf("%s\n", root->val);
	}
	else if (root->type == TK_STR)
	{
		printf("%c: ", c);
		show_node_list(root);
	}
	display_tree(root->left, 'l');
	if (root->type == TK_STR)
		return ;
	display_tree(root->right, 'r');
}

void	display_acc_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			printf("\\n");
		else if (str[i] > 32 && str[i] <= 126)
			printf("%c", str[i]);
		else
			printf("\\e");
		i++;
	}
	printf("\n");
}

void	display_list_envp(t_env *node)
{
	t_env	*temp;

	temp = node;
	while (temp)
	{
		printf("key: %s val: %s\n",	temp->key, temp->value);
		temp = temp->next;
	}
}

void	display_tree_all(t_tree *tree)
{
	display_tree(tree->top, 's');
	printf("cmd cmd_head: %s\n", tree->cmd.cmd_head);
	printf("\ncmd arr\n");
	display_str(tree->cmd.cmd_arr);
	printf("\npipe fd\n");
	for (int i = 0; i < tree->pipe_cnt; i++)
		printf("fd[0]: %d  , fd[1]: %d\n", tree->pipe_fd[i][0], tree->pipe_fd[i][1]);
	printf("\nheredocuments\n");
	display_str(tree->here_documets);
	printf("\npid\n");
	for (int i = 0; i < tree->pipe_cnt + 1; i++)
		printf("pid: %d\n", tree->pid[i]);
	printf("\nenv_list\n");
	display_list_envp(tree->env_list);
	printf("\nexport_list\n");
	display_list_envp(tree->export_list);
}
