/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:04:50 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 14:02:39 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	on_off_catch_signals(int on_off)
{
	extern int	rl_catch_signals;

	rl_catch_signals = on_off;
}

void	main_sigint(int signo)
{
	if (signo == SIGINT)
	{
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_sigterm(char *str)
{
	if (str != NULL)
		return ;
	write(1, "\x1b[1A", 4);
	write(1, "\033[12C", 5);
	write(1, "exit\n", 6);
	exit(0);
}

void	set_terminal(t_tree *tree)
{
	tcgetattr(STDIN_FILENO, &tree->cursor.org_term);
	tcgetattr(STDIN_FILENO, &tree->cursor.new_term);
	tcgetattr(STDIN_FILENO, &tree->cursor.child_term);
}

void	set_mode(t_tree *tree)
{
	set_terminal(tree);
	tree->cursor.new_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &tree->cursor.new_term);
}
