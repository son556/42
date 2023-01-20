/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:28:01 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 19:39:27 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		make_ttemp(char const *str, char c, char **temp);
static int		word_length(char const *s, int index, char c);
static void		filling_temp(char **temp, char const *s, char c, int size);
static void		ft_free(char **temp, int index);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		size;
	char	**temp;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
				i++;
			size++;
		}
	}
	temp = (char **)malloc((size + 1) * sizeof(char *));
	if (!temp)
		return (0);
	if (make_ttemp(s, c, temp))
		return (0);
	filling_temp(temp, s, c, size + 1);
	return (temp);
}

static int	make_ttemp(char const *str, char c, char **temp)
{
	int	index;
	int	cnt;
	int	i;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			cnt = word_length(str, i, c);
			temp[index] = (char *)malloc(cnt + 1);
			if (!temp[index])
			{
				ft_free(temp, index);
				return (1);
			}
			index++;
			i += cnt;
		}
	}
	return (0);
}

static int	word_length(char const *s, int index, char c)
{
	int	cnt;

	cnt = 0;
	while (s[index + cnt] && s[index + cnt] != c)
		cnt++;
	return (cnt);
}

static void	filling_temp(char **temp, char const *s, char c, int size)
{
	int	index;
	int	i;
	int	idx;

	index = 0;
	i = 0;
	idx = 0;
	while (index < size - 1)
	{
		if ((s[idx] == '\0' || s[idx] == c) && i > 0)
		{
			temp[index][i] = '\0';
			index++;
			i = 0;
		}
		else if (s[idx] != '\0' && s[idx] != c)
		{
			temp[index][i] = s[idx];
			i++;
		}
		idx++;
	}
	temp[index] = (void *)0;
}

static void	ft_free(char **temp, int index)
{
	int	idx;

	idx = 0;
	if (index > 0)
	{
		while (idx < index)
		{
			free(temp[idx]);
			idx++;
		}
	}
	free(temp);
}
