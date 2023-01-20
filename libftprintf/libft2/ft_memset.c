/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:46:16 by chanson           #+#    #+#             */
/*   Updated: 2022/11/11 16:53:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		temp[i++] = (unsigned char)value;
	}
	return (temp);
}
