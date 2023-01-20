/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:01:41 by chanson           #+#    #+#             */
/*   Updated: 2022/11/17 17:13:21 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cnt;
	t_list	*start;

	start = lst;
	cnt = 0;
	if (!lst)
		return (0);
	while (start -> next)
	{
		start = start -> next;
		cnt += 1;
	}
	return (cnt + 1);
}
