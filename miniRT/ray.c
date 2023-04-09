/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:10:52 by chanson           #+#    #+#             */
/*   Updated: 2023/04/09 21:30:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*set_ray(t_vec3 *orig, t_vec3 *dir)
{
	t_ray	*temp;

	temp = (t_ray *)malloc(sizeof(t_ray));
	temp->orig.x = orig->x;
	temp->orig.y = orig->y;
	temp->orig.z = orig->z;
	temp->dir.x = dir->x;
	temp->dir.y = dir->y;
	temp->dir.z = dir->z;
	return (temp);
}

t_vec3	*point_at(double t, t_ray *ray)
{
	t_vec3	*temp;

	temp = vec3_add(&(ray->orig), vec3_times(t, &(ray->dir)));
	return (temp);
}
