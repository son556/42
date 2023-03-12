/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:05:13 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 19:13:31 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	quote_check(char *str)
{
	int	end;

	end = ft_strlen(str) - 1;
	if (str[0] == '\'' && str[end] != '\'')
		return (FALSE);
	if (str[0] == '\"' && str[end] != '\"')
		return (FALSE);
	if (end == 0)
		return (FALSE);
	return (TRUE);
}

static int	check_quote_par(int par, int single_q, int double_q, char *str)
{
	if (par != 0)
		return (FALSE);
	if (single_q % 2 != 0 || double_q % 2 != 0)
		return (quote_check(str));
	return (TRUE);
}

int	check_str_valid(char *str)
{
	int	single_quote_flag;
	int	double_quote_flag;
	int	parentheses_flag;
	int	idx;

	single_quote_flag = 0;
	double_quote_flag = 0;
	parentheses_flag = 0;
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '(')
			parentheses_flag++;
		else if (str[idx] == ')')
			parentheses_flag--;
		else if (str[idx] == '\'')
			single_quote_flag++;
		else if (str[idx] == '\"')
			double_quote_flag++;
		idx++;
	}
	return (check_quote_par(parentheses_flag, single_quote_flag, \
		double_quote_flag, str));
}
