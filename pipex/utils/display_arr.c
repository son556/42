/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:23:34 by chanson           #+#    #+#             */
/*   Updated: 2023/01/12 17:45:02 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipe.h"

// test 용
void	display_arr(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (1)
	{
		printf("%s\n", str[i]);
		if (str[i] == NULL)
			break ;
		i++;
	}
}
