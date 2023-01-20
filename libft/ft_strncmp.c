/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:19:45 by chanson           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	c1;
	unsigned char	c2;

	idx = 0;
	while (idx < n)
	{
		c1 = *(s1 + idx);
		c2 = *(s2 + idx);
		if (c1 != c2)
			return (c1 - c2);
		if (*(s1 + idx) == '\0' || *(s2 + idx) == '\0')
			break ;
		idx++;
	}
	return (0);
}
