/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:56:44 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 15:40:52 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/test.h"

void	show_start_page(void)
{
	int		fd;
	char	*line;

	fd = open("./start_img", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		write(1, "\033[34;1m", 7);
		write(1, line, ft_strlen(line));
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	write(1, "\n", 1);
	close(fd);
	free(line);
}

int	main(int argc, char **argv, char **envp)
{
	t_tree	*tree;

	(void)argc;
	(void)argv;
	show_start_page();
	tree = tree_preset(envp);
	start_minishell(tree);
	return (0);
}
