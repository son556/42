/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:00:43 by chanson           #+#    #+#             */
/*   Updated: 2023/03/06 21:08:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

char	**ft_erase_null(char **cmd)
{
	int		i;
	char	**temp;
	int		cnt;

	i = -1;
	cnt = 0;
	while (cmd[++i])
	{
		if (ft_strscmp(cmd[i], "\"\"") == FALSE \
		&& ft_strscmp(cmd[i], "\'\'") == FALSE)
			cnt++;
	}
	temp = (char **)malloc(sizeof(char *) * (cnt + 1));
	temp[cnt] = NULL;
	i = -1;
	cnt = 0;
	while (cmd[++i])
	{
		if (ft_strscmp(cmd[i], "\"\"") || ft_strscmp(cmd[i], "\'\'"))
			continue ;
		temp[cnt] = ft_strcpy(cmd[i]);
		cnt++;
	}
	ft_free_str(cmd);
	return (temp);
}
