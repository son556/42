/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:16:09 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/08 15:16:10 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

static void	remove_double_quote(char *s, t_env *env_list, int *i)
{
	int	j;

	j = 0;
	(*i)++;
	while (s[*i + j] && s[*i + j] != '"')
	{
		if (s[*i + j] == '$')
			*i += print_env_value(s, *i + j + 1, env_list);
		else
		{
			printf("%c", s[*i + j]);
			j++;
		}
	}
	*i += j + 1;
}

static void	remove_single_quote(char *s, t_env *env_list, int *i)
{
	int	j;

	j = 0;
	(void)env_list;
	(*i)++;
	while (s[*i + j] && s[*i + j] != '\'')
	{
		printf("%c", s[*i + j]);
		j++;
	}
	*i += j + 1;
}

void	print_else(char *s, t_env *env_list, int *i)
{
	if (s[*i] == '$')
		*i += print_env_value(s, *i + 1, env_list);
	else
	{
		printf("%c", s[*i]);
		(*i)++;
	}
}

void	remove_quote_and_print(char *s, t_env *env_list)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			remove_double_quote(s, env_list, &i);
		else if (s[i] == '\'')
			remove_single_quote(s, env_list, &i);
		else
			print_else(s, env_list, &i);
	}
}
