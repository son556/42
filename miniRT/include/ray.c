/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:22:09 by chanson           #+#    #+#             */
/*   Updated: 2023/04/18 13:25:39 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_init(t_point3 point, t_dir direction)
{
	t_ray	ray;

	ray.point = point;
	ray.direction = direction;
	return (ray);
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	target;

	target = add_vec3(ray.point, mul_vec3(ray.direction, t));
	return (target);
}
