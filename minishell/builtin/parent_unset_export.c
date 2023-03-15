/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_unset_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:00:52 by hyungjpa          #+#    #+#             */
/*   Updated: 2023/03/07 11:00:53 by hyungjpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

void	set_export(t_tree *info)
{
	int		check_args;
	char	**temp;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "export"))
		return ;
	temp = export_split(info->origin);
	if (!temp)
		return ;
	info->export_temp = envp_copy(temp);
	if (temp[1])
	{
		check_args = export_args(info, temp);
		if (check_args)
		{
			ft_free_str(temp);
			return ;
		}
		ft_free_str(info->envp_val);
		info->envp_val = env_to_envp(info->env_list);
	}
	ft_free_str(temp);
}

void	set_unset(t_tree *info)
{
	int	res1;
	int	res2;

	if (!ft_strscmp(info->cmd.cmd_arr[0], "unset"))
		return ;
	res1 = list_unset(info->cmd.cmd_arr, &(info->env_list));
	if (res1 > 0)
		return ;
	res2 = list_unset(info->cmd.cmd_arr, &(info->export_list));
	ft_free_str(info->envp_val);
	info->envp_val = env_to_envp(info->env_list);
}

void	parent_unset_export(t_tree *info)
{
	set_export(info);
	set_unset(info);
}
