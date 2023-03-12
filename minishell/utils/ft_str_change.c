/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:09:25 by chanson           #+#    #+#             */
/*   Updated: 2023/03/01 18:11:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*ft_str_change(char *old, char *new)
{
	char	*temp;
	int		i;

	if (new == NULL)
		return (old);
	if (old != NULL)
		free(old);
	i = 0;
	while (new[i])
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	temp[i] = '\0';
	i = -1;
	while (new[++i])
		temp[i] = new[i];
	return (temp);
}
