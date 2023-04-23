/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:54:18 by chanson           #+#    #+#             */
/*   Updated: 2023/04/23 19:14:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit.h"

// t_obj	object_init(int type, t_point3 point, t_vec3 normal, t_color3 color)
// {
// 	t_obj	object;

// 	object.type = type;
// 	object.point = point;
// 	object.n_vec = normal;
// 	object.color = color;
// 	object.next = NULL;
// 	return (object);
// }

void	add_objlist(t_objlist *list, t_obj *object)
{
	t_obj	*temp;

	if (list->first == NULL)
	{
		list->first = object;
		list->list_cnt = 1;
		return ;
	}
	temp = list->first;
	while (temp->next)
		temp = temp->next;
	temp->next = object;
	list->list_cnt++;
}
