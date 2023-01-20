/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:53:25 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 19:41:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_trim(char s1_c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1_c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_left_strtrim(char const *s1, char const *set)
{
	int	idx;

	idx = 0;
	while (s1[idx])
	{
		if (!check_trim(s1[idx], set))
			break ;
		idx++;
	}
	return (idx);
}

static int	check_right_strtrim(char const *s1, char const *set, int len_s1)
{
	int	idx;

	idx = len_s1 - 1;
	while (idx >= 0)
	{
		if (!check_trim(s1[idx], set))
			break ;
		idx--;
	}
	return (idx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		start;
	int		end;
	int		idx;
	int		len_s1;

	if (!s1)
		return (0);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	start = check_left_strtrim(s1, set);
	end = check_right_strtrim(s1, set, len_s1);
	if (start > end)
		temp = (char *)malloc(1);
	else
		temp = (char *)malloc(end - start + 2);
	if (!temp)
		return (temp);
	idx = 0;
	while (start <= end)
		temp[idx++] = s1[start++];
	temp[idx] = '\0';
	return (temp);
}
