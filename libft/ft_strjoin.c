/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:55 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 21:25:13 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strllen(char const *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		len_s1;
	int		len_s2;
	int		idx;
	int		index;

	len_s1 = ft_strllen(s1);
	len_s2 = ft_strllen(s2);
	if (!s1 && !s2)
		return ((char *)0);
	temp = (char *)malloc(len_s1 + len_s2 + 1);
	if (!temp)
		return (temp);
	idx = 0;
	while (s1 && s1[idx])
	{
		temp[idx] = s1[idx];
		idx++;
	}
	index = 0;
	while (s2 && s2[index])
		temp[idx++] = s2[index++];
	temp[idx] = '\0';
	return (temp);
}
