/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:31:43 by chanson           #+#    #+#             */
/*   Updated: 2023/05/10 20:02:17 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_norm	find_hit_function(t_ray ray, t_obj obj, double t_max)
{
	if (obj.type == SPHERE)
		return (hit_sphere(obj.sphere, ray, t_max));
	if (obj.type == CYLINDER)
		return (hit_cylinder(obj.cylinder, ray, t_max));
	if (obj.type == PLANE)
		return (hit_plane(obj.plane, ray, t_max));
	if (obj.type == CUBE)
		return (hit_cube(obj.cube, ray, t_max, &obj.color));
	if (obj.type == CONE)
		return (hit_cone(obj.cone, ray, t_max));
	return (hit_paraboloid(obj.para, ray, t_max));
}

int	shade(t_norm norm, t_obj *obj, int n, int m)
{
	t_norm	temp;
	t_ray	ray;
	double	t_max;
	int		i;

	ray.point = norm.hit;
	ray.direction = normalize_vec3(sub_vec3(norm.light.point, norm.hit));
	t_max = len_vec3(sub_vec3(norm.hit, norm.light.point));
	i = -1;
	while (++i < n)
	{
		if (i == m || i == 3)
			continue ;
		temp = find_hit_function(ray, obj[i], t_max);
		if (temp.root > 0.0)
			return (1);
	}
	return (0);
}

int	front_or_back(t_ray ray, t_norm norm)
{
	double	dif;

	dif = dot_vec3(ray.direction, norm.n_vec);
	if (dif < 0)
		return (1);
	return (0);
}

t_ray	diffuse_ray(t_norm norm)
{
	t_ray	new_ray;
	t_vec3	temp;
	t_vec3	cen;

	new_ray.point = norm.hit;
	cen = add_vec3(norm.hit, norm.n_vec);
	while (1)
	{
		temp.x = random_min_max(-1, 1);
		temp.y = random_min_max(-1, 1);
		temp.z = random_min_max(-1, 1);
		if (len_vec3(temp) < 1)
			break ;
	}
	new_ray.direction = normalize_vec3(sub_vec3(\
		add_vec3(cen, temp), new_ray.point));
	return (new_ray);
}
