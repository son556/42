/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:53:54 by chanson           #+#    #+#             */
/*   Updated: 2022/11/22 19:25:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_str(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		idx;
	char	*str;
	char	*temp;

	str = NULL;
	if ((unsigned int)ft_len_str(s) < start || len < 1)
	{
		temp = malloc(1);
		temp[0] = '\0';
		return (temp);
	}
	if ((unsigned int)ft_len_str(s + start) < len)
		str = (char *)malloc(sizeof(char) * (ft_len_str(s + start) + 1));
	else
		str = (char *)malloc(len + 1);
	idx = 0;
	if (!str)
		return (str);
	while (s[idx + start] && (unsigned long)idx < len)
	{
		str[idx] = s[idx + start];
		idx++;
	}
	str[idx] = '\0';
	return (str);
}
