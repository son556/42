/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:54:11 by chanson           #+#    #+#             */
/*   Updated: 2022/11/11 16:56:49 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	char	*temp;

	idx = 0;
	while (s[idx])
		idx++;
	temp = (char *)malloc(idx + 1);
	if (!temp)
		return (temp);
	idx = 0;
	while (s[idx])
	{
		temp[idx] = f(idx, s[idx]);
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
