/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:31:43 by chanson           #+#    #+#             */
/*   Updated: 2023/05/08 21:53:28 by chanson          ###   ########.fr       */
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

// t_color3	antialiasing(t_ray ray, t_obj obj, t_norm norm, t_color3 col)
// {
// 	t_norm		temp;
// 	int			i;
// 	t_color3	color;
// 	double		t_max;
// 	t_ray		temp_ray;

// 	color = col;
// 	i = -1;
// 	t_max = INFINITY;
// 	while (++i < 9)
// 	{
// 		temp_ray.point = ray.point;
// 		temp_ray.direction = add_vec3(ray.direction, vec3_rand());
// 		temp = find_hit_function(ray, obj, t_max);
// 		if (temp.root > 0.0)
// 		{
// 			temp.light.ratio = dot_vec3(temp.n_vec, \
// 			normalize_vec3(sub_vec3(temp.light.point, temp.hit)));
// 			temp.light.ratio += 0.3;
// 			temp.light.ratio = ft_minmax(temp.light.ratio, 0, 1);
// 			color += mul_vec3(col, temp.light.ratio);
// 		}
// 	}
// 	color = mul_vec3(vec3init(0, 1, 1), norm->light.ratio);	
// }
