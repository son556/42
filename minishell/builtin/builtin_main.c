/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:17:42 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/10 15:53:43 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

int	cd_echo_env_check(t_tree *info)
{
	int	cd_check;
	int	echo_check;
	int	env_check;

	cd_check = do_cd(info);
	echo_check = do_echo(info);
	env_check = do_env(info);
	if (cd_check != 1)
		return (cd_check);
	if (echo_check != 1)
		return (echo_check);
	if (env_check != 1)
		return (env_check);
	return (1);
}

int	export_pwd_unset_check(t_tree *info)
{
	int	export_check;
	int	pwd_check;
	int	unset_check;

	export_check = do_export(info);
	pwd_check = do_pwd(info);
	unset_check = do_unset(info);
	if (export_check != 1)
		return (export_check);
	if (pwd_check != 1)
		return (pwd_check);
	if (unset_check != 1)
		return (unset_check);
	return (1);
}

int	builtin_pipe(t_tree *info)
{
	int	exit_check;
	int	check_1;
	int	check_2;

	exit_check = 0;
	if (info->outfile != 0)
		dup2(info->outfile, STDOUT_FILENO);
	check_1 = cd_echo_env_check(info);
	if (check_1 != 1)
		return (check_1);
	check_2 = export_pwd_unset_check(info);
	if (check_2 != 1)
		return (check_2);
	exit_check = do_exit_pipe(info);
	if (exit_check != 0)
		return (exit_check);
	exit(info->exit_code);
	return (exit_check);
}

int	builtin_no_pipe(t_tree *info)
{
	int	exit_check;
	int	check_1;
	int	check_2;

	exit_check = 0;
	if (info->outfile != 0)
		dup2(info->outfile, STDOUT_FILENO);
	check_1 = cd_echo_env_check(info);
	if (check_1 != 1)
		return (check_1);
	check_2 = export_pwd_unset_check(info);
	if (check_2 != 1)
		return (check_2);
	exit_check = do_exit_no_pipe(info);
	if (exit_check != 0)
		return (exit_check);
	exit(info->exit_code);
	return (exit_check);
}
