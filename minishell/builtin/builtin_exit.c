/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:40:02 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/13 13:30:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	check_digit(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] >= '0' && str[idx] <= '9')
		idx++;
	if (idx == ft_strlen(str))
		return (1);
	return (0);
}

int	check_exit_argu(t_tree *info, int size)
{
	if (check_digit(info->cmd.cmd_arr[1]))
	{
		if (size == 2)
		{
			info->exit_code = ft_atoi(info->cmd.cmd_arr[1]);
			return (0);
		}
		else
			return (print_error_1("exit: too many arguments"));
	}
	else
	{
		print_error_3("exit: ", info->cmd.cmd_arr[1], \
		": numeric argument required");
		info->exit_code = 255;
	}
	return (0);
}

int	do_exit_pipe(t_tree *info)
{
	int	size;
	int	i;

	i = 0;
	if (!ft_strscmp(info->cmd.cmd_arr[0], "exit"))
		return (1);
	size = str_size(info->cmd.cmd_arr);
	if (size == 1)
		return (0);
	else
		return (check_exit_argu(info, size));
	return (0);
}

int	do_exit_no_pipe(t_tree *info)
{
	int	size;
	int	i;

	i = 0;
	if (!ft_strscmp(info->cmd.cmd_arr[0], "exit"))
		return (1);
	size = str_size(info->cmd.cmd_arr);
	printf("exit\n");
	if (size == 1)
		return (0);
	else
		return (check_exit_argu(info, size));
	return (0);
}
