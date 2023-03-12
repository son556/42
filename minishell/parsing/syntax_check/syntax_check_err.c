/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check_err.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:29:55 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static int	_syntax_err_check(char	*str)
{
	char	**str_arr;
	char	*string;

	str_arr = NULL;
	string = NULL;
	string = ft_strtrim_couple_check(str, '(', ')');
	if (string[0] != '(')
	{
		str_arr = ft_split(string);
		if (syntax_check(str_arr) == FALSE)
		{
			free(str);
			ft_free_str(str_arr);
			return (FALSE);
		}
	}
	free(string);
	ft_free_str(str_arr);
	return (TRUE);
}

int	syntax_err_check(char **temp)
{
	int		i;

	i = -1;
	while (temp[++i])
	{
		if (temp[i][0] == '(')
		{
			if (_syntax_err_check(temp[i]) == FALSE)
				return (FALSE);
		}
	}
	if (syntax_check(temp) == FALSE)
		return (FALSE);
	return (TRUE);
}
