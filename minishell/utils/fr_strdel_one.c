/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_strdel_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:53:49 by chanson           #+#    #+#             */
/*   Updated: 2023/03/07 19:28:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	*fr_strdel_one(char *str, int index)
{
	char	*temp;
	char	*temp_2;

	temp = ft_strcpy_index(str, 0, index - 2);
	temp_2 = ft_strcpy_index(str, index, ft_strlen(str) - 1);
	temp = ft_strstr(temp, temp_2);
	free(temp_2);
	return (temp);
}
