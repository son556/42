/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_signal_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:42:41 by chanson           #+#    #+#             */
/*   Updated: 2023/03/08 14:15:27 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	sig_handler_ctrl_c(int signo)
{
	(void)signo;
	write(1, "^C\n", 3);
	exit(130);
}

void	sig_handler_ctrl_d(int signo)
{
	(void)signo;
	write(1, "exit\n", 5);
	exit(0);
}

void	do_signal_handle(int status)
{
	if (status == PARENT)
	{
		signal(SIGINT, main_sigint);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (status == CHILD || status == HEREDOC)
	{
		if (status == CHILD)
		{
			signal(SIGINT, sig_handler_ctrl_c);
			signal(SIGQUIT, SIG_DFL);
			signal(SIGTERM, sig_handler_ctrl_d);
		}
		if (status == HEREDOC)
			signal(SIGINT, sig_heredoc_ctrl_c);
	}
	else if (status == WAIT_CHILD)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	reset_terminal(t_tree *tree)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &tree->cursor.org_term);
}

void	set_child_mode(t_tree *tree)
{
	tree->cursor.child_term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &tree->cursor.new_term);
}
