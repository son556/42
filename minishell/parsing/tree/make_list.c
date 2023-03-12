/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:37:02 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	append_node_list(char *str, int type, t_list *list)
{
	t_token	*token;

	token = (t_token *)malloc(sizeof(t_token));
	token->val = ft_strcpy(str);
	if (!token || !(token->val))
		return (FALSE);
	token->type = type;
	token->right = NULL;
	if (list->first == NULL && list->last == NULL)
	{
		token->left = NULL;
		list->first = token;
		list->last = token;
	}
	else
	{
		token->left = list->last;
		list->last->right = token;
		list->last = token;
	}
	return (TRUE);
}

int	make_list(char **temp, t_list *list)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (append_node_list(temp[i], decide_type(temp[i]), list) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
