/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:35:48 by chanson           #+#    #+#             */
/*   Updated: 2022/11/21 09:42:40 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	int		i;

	temp = (void *)malloc(size * count);
	if (temp == NULL)
		return (0);
	i = 0;
	while ((unsigned long)i < count * size)
	{
		*(unsigned char *)(temp + i) = (unsigned char)0;
		i++;
	}
	return ((void *)temp);
}
