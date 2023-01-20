/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:44:49 by chanson           #+#    #+#             */
/*   Updated: 2023/01/13 20:48:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

char	*str_cp_limit(char *str, int idx)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (idx + 1));
	temp[idx + 1] = '\0';
	i = 0;
	while (i <= idx)
	{
		temp[i] = str[i];
		i++;
	}
	return (temp);
}
