/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:06:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*_ft_strtrim(char *str, int i, int j, int cnt)
{
	char	*result;
	int		idx;

	result = (char *)malloc(sizeof(char) * (cnt + 1));
	result[cnt] = '\0';
	idx = 0;
	while (i <= j)
	{
		result[idx] = str[i];
		i++;
		idx++;
	}
	return (result);
}

char	*ft_strtrim_couple(char *str, char c1, char c2)
{
	int		cnt;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			i++;
		else
			break ;
	}
	j = 0;
	while (str[j])
		j++;
	--j;
	while (str[j])
	{
		if (str[j] == c2)
			--j;
		else
			break ;
	}
	cnt = j - i + 1;
	return (_ft_strtrim(str, i, j, cnt));
}

char	*ft_strtrim(char *str, char c)
{
	int		cnt;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
			break ;
	}
	j = 0;
	while (str[j])
		j++;
	--j;
	while (str[j])
	{
		if (str[j] == c)
			--j;
		else
			break ;
	}
	cnt = j - i + 1;
	return (_ft_strtrim(str, i, j, cnt));
}

char	*ft_strtrim_couple_check(char *str, char c1, char c2)
{
	int		cnt;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			i++;
		break ;
	}
	j = 0;
	while (str[j])
		j++;
	--j;
	while (str[j])
	{
		if (str[j] == c2)
			--j;
		break ;
	}
	cnt = j - i + 1;
	return (_ft_strtrim(str, i, j, cnt));
}
