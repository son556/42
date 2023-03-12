/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_redir_ord.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:44:57 by chanson           #+#    #+#             */
/*   Updated: 2023/03/10 15:51:44 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

static void	_get_ord(char **temp, int *i, int *ord_fd, int *cnt)
{
	close_fd(cnt, *ord_fd);
	*ord_fd = open(temp[++(*i)], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*ord_fd == -1)
		write(2, "open_error\n", 11);
}

int	get_ord(char **temp)
{
	int	i;
	int	ord_fd;
	int	cnt;

	i = -1;
	ord_fd = 0;
	cnt = 0;
	while (!ft_strscmp(temp[++i], "|") && temp[i])
	{
		if (ft_strscmp(temp[i], ">"))
		{
			close_fd(&cnt, ord_fd);
			ord_fd = open(temp[++i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (ord_fd == -1)
				write(2, "open_error\n", 11);
		}
		else if (ft_strscmp(temp[i], ">>"))
			_get_ord(temp, &i, &ord_fd, &cnt);
		if (ord_fd == -1)
			break ;
	}
	return (ord_fd);
}
