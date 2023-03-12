/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:23:35 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	make_type_list(int *type_list, char **temp)
{
	int				i;

	i = -1;
	while (temp[++i])
	{
		if (ft_strscmp(temp[i], "<") == TRUE)
			type_list[i] = TK_IRD;
		else if (ft_strscmp(temp[i], ">") == TRUE)
			type_list[i] = TK_ORD;
		else if (ft_strscmp(temp[i], "<<") == TRUE)
			type_list[i] = TK_HRD;
		else if (ft_strscmp(temp[i], ">>") == TRUE)
			type_list[i] = TK_ARD;
		else if (ft_strscmp(temp[i], "|") == TRUE)
			type_list[i] = TK_PIPE;
		else if (ft_strscmp(temp[i], "&&") == TRUE)
			type_list[i] = TK_AND;
		else if (ft_strscmp(temp[i], "||") == TRUE)
			type_list[i] = TK_OR;
		else
			type_list[i] = TK_STR;
	}
}

static int	check_first(int *type_list, char**temp)
{
	if (type_list[0] == TK_PIPE)
		return (FALSE);
	if (type_list[0] == TK_AND)
		return (FALSE);
	if (type_list[0] == TK_OR)
		return (FALSE);
	if (temp[0][0] == ')')
		return (FALSE);
	return (TRUE);
}

static int	check_last(int *type_list, char **temp, int idx)
{
	int	i;

	if (type_list[idx] == TK_IRD)
		return (FALSE);
	if (type_list[idx] == TK_ORD)
		return (FALSE);
	if (type_list[idx] == TK_HRD)
		return (FALSE);
	if (type_list[idx] == TK_ARD)
		return (FALSE);
	if (type_list[idx] == TK_PIPE)
		return (FALSE);
	if (type_list[idx] == TK_OR)
		return (FALSE);
	if (type_list[idx] == TK_AND)
		return (FALSE);
	i = 0;
	while (temp[idx][i])
		i++;
	if (temp[idx][i - 1] == '(')
		return (FALSE);
	return (TRUE);
}

static int	free_type(int *type_list)
{
	free(type_list);
	return (FALSE);
}

int	syntax_check(char **temp)
{
	int		idx;
	int		*type_list;
	int		cnt;

	cnt = 0;
	while (temp[cnt])
		cnt++;
	type_list = (int *)malloc(sizeof(int) * (cnt));
	if (!type_list)
		return (FALSE);
	make_type_list(type_list, temp);
	idx = -1;
	while (temp[++idx])
	{
		if (idx == 0 && check_first(type_list, temp) == FALSE)
			return (free_type(type_list));
		if (idx == cnt - 1 && check_last(type_list, temp, idx) == FALSE)
			return (free_type(type_list));
		if (idx != cnt - 1 && check_pattern(temp, type_list, idx) == FALSE)
			return (free_type(type_list));
		if (type_list[idx] == TK_STR && check_str_valid(temp[idx]) == FALSE)
			return (free_type(type_list));
	}
	free(type_list);
	return (TRUE);
}
