/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:07:35 by chanson           #+#    #+#             */
/*   Updated: 2023/01/13 20:38:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipe_bonus.h"

int	str_cmp(char *str, char *cmp)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != cmp[i])
			return (0);
	}
	return (1);
}
