/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:59:29 by chanson           #+#    #+#             */
/*   Updated: 2022/11/17 19:45:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst != NULL && new != NULL)
	{
		last = *lst;
		while (last -> next)
			last = last -> next;
		last -> next = new;
	}
	else if (*lst == NULL && new != NULL)
		*lst = new;
}
