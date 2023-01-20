/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:53:58 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 19:40:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlength(const char *needle);
static int	cmp_str(const char *haystack, const char *needle, size_t index);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	needle_len;

	needle_len = (size_t)ft_strlength(needle);
	if (!needle || *needle == '\0')
		return ((char *)haystack);
	if (needle_len > len && len == 0)
		return (0);
	index = 0;
	while (haystack[index] && index < len)
	{
		if (index + needle_len > len)
			return (0);
		if (haystack[index] == *needle)
			if (cmp_str(haystack, needle, index))
				return ((char *)(haystack + index));
		index++;
	}
	return (0);
}

static int	cmp_str(const char *haystack, const char *needle, size_t index)
{
	size_t	idx;

	idx = 0;
	while (needle[idx])
	{
		if (haystack[index] != needle[idx])
			return (0);
		index++;
		idx++;
	}
	return (1);
}

static int	ft_strlength(const char *needle)
{
	int	i;

	i = 0;
	while (needle[i])
		i++;
	return (i);
}
