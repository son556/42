/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:58 by chanson           #+#    #+#             */
/*   Updated: 2023/05/03 19:56:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_norm	hit_sphere(t_sphere sph, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	disc.ac = sub_vec3(ray.point, sph.center);
	disc.a = dot_vec3(ray.direction, ray.direction);
	disc.b = dot_vec3(disc.ac, ray.direction);
	disc.c = dot_vec3(disc.ac, disc.ac) - pow(sph.radius, 2);
	disc.discrim = disc.b * disc.b - disc.a * disc.c;
	if (disc.discrim < 0)
		norm.root = 0;
	disc.root = (-disc.b - sqrt(disc.discrim)) / disc.a;
	if (disc.root < 0.001 || disc.root > t_max)
	{
		disc.root = (-disc.b + sqrt(disc.discrim)) / disc.a;
		if (disc.root < 0.001 || disc.root > t_max)
			norm.root = 0;
	}
	norm.root = disc.root;
	norm.n_vec = normalize_vec3(sub_vec3(ray_at(ray, norm.root), sph.center));
	return (norm);
}

t_norm	hit_plane(t_plane pln, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	if (dot_vec3(ray.direction, pln.n_vec) == 0)
	{
		norm.root = 0;
		return (norm);
	}
	if (dot_vec3(sub_vec3(ray.point, pln.center), pln.n_vec) == 0)
	{
		norm.root = 0;
		return (norm);
	}
	disc.ac = sub_vec3(ray.point, pln.center);
	disc.a = -1 * dot_vec3(disc.ac, pln.n_vec);
	disc.b = dot_vec3(ray.direction, pln.n_vec);
	disc.root = disc.a / disc.b;
	if (disc.root < 0.0001 || disc.root > t_max)
		norm.root = 0;
	norm.root = disc.root;
	norm.n_vec = pln.n_vec;
	return (norm);
}

static t_norm	find_hit_function(t_ray ray, t_obj obj, double t_max)
{
	if (obj.type == SPHERE)
		return (hit_sphere(obj.sphere, ray, t_max));
	if (obj.type == CYLINDER)
		return (hit_cylinder(obj.cylinder, ray, t_max));
	if (obj.type == PLANE)
		return (hit_plane(obj.plane, ray, t_max));
	if (obj.type == CUBE)
		return (hit_cube(obj.cube, ray, t_max, &obj.cube.color));
	if (obj.type == CONE)
		return (hit_cone(obj.cone, ray, t_max));
	return (hit_paraboloid(obj.para, ray, t_max));
}

t_color3	ray_color(t_ray ray, t_obj *obj, int n)
{
	t_vec3	color;
	t_norm	norm;
	t_light	light;
	int		i;
	double	temp;

	norm.t_max = INFINITY;
	temp = norm.t_max;
	i = -1;
	while (++i < n)
	{
		norm = find_hit_function(ray, obj[i], norm.t_max);
		if (norm.root == 0.0)
			norm.t_max = temp;
		if (norm.root > 0.0)
		{
			norm.hit = ray_at(ray, norm.root);
			light.ratio = dot_vec3(norm.n_vec, normalize_vec3(vec3init(1, 1, 0)));
			light.ratio = ft_minmax(light.ratio, 0, 1);
			color = mul_vec3(vec3init(0, 1, 1), light.ratio);
			norm.t_max = norm.root;
			temp = norm.t_max;
			return (color);
		}
	}
	t_vec3	unit_vec = normalize_vec3(ray.direction);
	norm.root = 0.5 * (unit_vec.y + 1.0);
	color = vec3init(1.0 - 0.5 * norm.root, 1.0 - 0.3 * norm.root, 1.0);
	return (color);
}
