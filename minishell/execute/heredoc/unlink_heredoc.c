/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlink_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:16:33 by chanson           #+#    #+#             */
/*   Updated: 2023/03/11 21:27:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/test.h"

void	unlink_heredoc(t_tree *tree)
{
	int	i;

	i = 0;
	while (tree->here_documets[i])
	{
		if (unlink(tree->here_documets[i]) == -1)
			ft_error("unlink error\n");
		i++;
	}
}
