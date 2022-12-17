/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:47:51 by chanson           #+#    #+#             */
/*   Updated: 2022/12/13 21:57:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_inm(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	push_sa(a);
	if (*cmd_lst == NULL)
		*cmd_lst = ft_cmdnew("sa");
	else
		ft_cmdadd_back(cmd_lst, "sa");
}

void	sort_min(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	push_sa(a);
	if (*cmd_lst == NULL)
		*cmd_lst = ft_cmdnew("sa");
	else
		ft_cmdadd_back(cmd_lst, "sa");
	push_rra(a);
	ft_cmdadd_back(cmd_lst, "rra");
}

void	sort_mni(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	push_ra(a);
	if (*cmd_lst == NULL)
		*cmd_lst = ft_cmdnew("ra");
	else
		ft_cmdadd_back(cmd_lst, "ra");
}

void	sort_nmi(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	push_sa(a);
	if (*cmd_lst == NULL)
		*cmd_lst = ft_cmdnew("sa");
	else
		ft_cmdadd_back(cmd_lst, "sa");
	push_ra(a);
	ft_cmdadd_back(cmd_lst, "ra");
}

void	sort_imn(t_LinkedDeque *a, t_cmd **cmd_lst)
{
	push_rra(a);
	if (*cmd_lst == NULL)
		*cmd_lst = ft_cmdnew("rra");
	else
		ft_cmdadd_back(cmd_lst, "rra");
}
