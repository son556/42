/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:48:28 by chanson           #+#    #+#             */
/*   Updated: 2023/04/17 17:36:40 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

int	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int				hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

int	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	return (hit_result);
}
