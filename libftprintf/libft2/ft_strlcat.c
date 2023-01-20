/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:57:37 by chanson           #+#    #+#             */
/*   Updated: 2022/11/16 20:32:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		idx;
	size_t	len_dest;
	size_t	len_src;

	idx = 0;
	if (size == 0 && src)
		return ((size_t)ft_strlen(src));
	len_dest = (size_t)ft_strlen(dest);
	len_src = (size_t)ft_strlen(src);
	if (len_dest + 1 > size)
		return (len_src + size);
	while (*(src + idx) != '\0' && len_dest + idx + 1 < size)
	{
		*(dest + idx + len_dest) = *(src + idx);
		idx++;
	}
	*(dest + idx + len_dest) = '\0';
	return (len_dest + len_src);
}
