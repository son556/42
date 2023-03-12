/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:03:46 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	ft_split_and(char ***temp, char *str, int idx)
{
	char	*buff;
	int		cnt;

	cnt = 0;
	buff = NULL;
	buff = ft_strcjoin(buff, str[idx++]);
	if (str[idx] == '&')
	{
		buff = ft_strcjoin(buff, str[idx]);
		cnt++;
	}
	*temp = ft_strsjoin(*temp, buff);
	return (cnt);
}

int	ft_split_par(char ***temp, char *str, int idx)
{
	char	*buff;
	int		par_flag;
	int		cnt;

	par_flag = 1;
	cnt = 0;
	buff = NULL;
	buff = ft_strcjoin(buff, str[idx++]);
	while (1)
	{
		if (str[idx] == '(')
			par_flag++;
		else if (str[idx] == ')')
			par_flag--;
		buff = ft_strcjoin(buff, str[idx]);
		if (par_flag == 0)
			break ;
		if (str[idx] == '\0')
			break ;
		cnt++;
		idx++;
	}
	*temp = ft_strsjoin(*temp, buff);
	return (cnt + 1);
}
