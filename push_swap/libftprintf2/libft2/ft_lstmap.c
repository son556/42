/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:23:50 by chanson           #+#    #+#             */
/*   Updated: 2022/11/22 19:31:30 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*list;
	void	*result;

	if (!lst || !f || !del)
		return (0);
	result = f(lst -> content);
	if (!result)
		return (0);
	start = ft_lstnew(result);
	lst = lst -> next;
	while (lst)
	{
		result = f(lst -> content);
		list = ft_lstnew(result);
		if (list == NULL || result == NULL)
		{
			ft_lstclear(&start, del);
			break ;
		}
		ft_lstadd_back(&start, list);
		lst = lst -> next;
	}
	return (start);
}
