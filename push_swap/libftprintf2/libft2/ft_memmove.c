/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:20:52 by chanson           #+#    #+#             */
/*   Updated: 2022/11/14 22:10:11 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			idx;

	if (!dst && !src)
		return (0);
	if (src + len >= dst && dst > src)
	{
		idx = len - 1;
		while (len)
		{
			*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
			len--;
			idx--;
		}
	}
	else
	{
		idx = 0;
		while (idx < len)
		{
			*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
			idx++;
		}
	}
	return (dst);
}
