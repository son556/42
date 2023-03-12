/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:29:46 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 15:07:09 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (1)
	{
		if (s[idx] == (char) c)
			return (idx);
		if (s[idx] == '\0')
			break ;
		idx++;
	}
	return (-1);
}

int	ft_strllen_gnl(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*temper;
	int		len_s1;
	int		len_s2;
	int		idx;
	int		index;

	len_s1 = ft_strllen_gnl(s1);
	len_s2 = ft_strllen_gnl(s2);
	temper = (char *)malloc(len_s1 + len_s2 + 1);
	if (!temper)
		return (temper);
	idx = 0;
	while (s1 && s1[idx])
	{
		temper[idx] = s1[idx];
		idx++;
	}
	index = 0;
	while (s2 && s2[index])
		temper[idx++] = s2[index++];
	free(s1);
	s1 = NULL;
	temper[idx] = '\0';
	return (temper);
}

char	*ft_strdup_gnl(const char *s1, int end)
{
	char	*tempo;
	int		idx;

	idx = 0;
	tempo = NULL;
	while (s1[idx])
		idx++;
	tempo = (char *)malloc(idx + 1);
	if (!tempo)
		return (tempo);
	idx = 0;
	while (idx <= end && s1[idx])
	{
		tempo[idx] = s1[idx];
		idx++;
	}
	tempo[idx] = '\0';
	return (tempo);
}
