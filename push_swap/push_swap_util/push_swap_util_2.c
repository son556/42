/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:25:51 by chanson           #+#    #+#             */
/*   Updated: 2022/12/14 20:06:32 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_cmd	*ft_cmdnew(char *content)
{
	t_cmd	*new_cmd;

	new_cmd = malloc(sizeof(t_cmd));
	if (!new_cmd)
		return (0);
	new_cmd->command = content;
	new_cmd->next = NULL;
	return (new_cmd);
}

void	ft_cmdadd_back(t_cmd **cmd, char *content)
{
	t_cmd	*last;
	t_cmd	*new;

	new = ft_cmdnew(content);
	if (!new)
		return ;
	if (*cmd != NULL && new != NULL)
	{
		last = *cmd;
		while ((*cmd)->next)
			*cmd = (*cmd)->next;
		(*cmd)->next = new;
		*cmd = last;
	}
}

void	ft_cmdclear(t_cmd **lst)
{
	t_cmd	*temp;

	if (lst != NULL)
	{
		while (1)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
			if (!(*lst))
				break ;
		}
	}
}

int	ft_abs(int a)
{
	if (a < 0)
		a = -1 * a;
	return (a);
}

void	display_cmd(t_cmd *cmd_lst)
{
	while (cmd_lst)
	{
		ft_printf("%s\n", cmd_lst->command);
		cmd_lst = cmd_lst->next;
	}
}
