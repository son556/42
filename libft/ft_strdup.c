/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:35:53 by chanson           #+#    #+#             */
/*   Updated: 2022/11/11 16:55:55 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*temp;
	int		idx;

	idx = 0;
	temp = NULL;
	while (s1[idx])
		idx++;
	temp = (char *)malloc(idx + 1);
	if (!temp)
		return (temp);
	idx = 0;
	while (s1[idx])
	{
		temp[idx] = s1[idx];
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
