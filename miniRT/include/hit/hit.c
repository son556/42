/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:58 by chanson           #+#    #+#             */
/*   Updated: 2023/05/06 21:49:38 by chanson          ###   ########.fr       */
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
	norm.root = 0;
	if (disc.discrim < 0)
		return (norm);
	disc.root = (-disc.b - sqrt(disc.discrim)) / disc.a;
	if (disc.root < 0.001 || disc.root > t_max)
	{
		disc.root = (-disc.b + sqrt(disc.discrim)) / disc.a;
		if (disc.root < 1e-5 || disc.root > t_max)
			return (norm);
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

static int	shade(t_norm norm, t_obj *obj, int n, int m)
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

t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_vec3	color;
	int		i;
	double	temp;
	t_norm	tmp_n;

	tmp_n.t_max = INFINITY;
	temp = tmp_n.t_max;
	i = -1;
	color.x = -1000;
	while (++i < n)
	{
		if (i == 1)
			continue ;
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		tmp_n.t_max = temp;
		if (tmp_n.root > 0.0)
		{
			norm->root = tmp_n.root;
			norm->n_vec = tmp_n.n_vec;
			norm->hit = ray_at(ray, norm->root);
			norm->light.ratio = dot_vec3(norm->n_vec, \
				normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
			norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
			color = mul_vec3(vec3init(0, 1, 1), norm->light.ratio);
			norm->t_max = tmp_n.root;
			temp = tmp_n.root;
			tmp_n.t_max = temp;
			if (shade(*norm, obj, n, i))
				color = vec3init(0, 0, 0);
		}
	}
	if (color.x != -1000)
		return (color);
	t_vec3	unit_vec = normalize_vec3(ray.direction);
	norm->root = 0.5 * (unit_vec.y + 1.0);
	color = vec3init(1.0 - 0.5 * norm->root, 1.0 - 0.3 * norm->root, 1.0);
	return (color);
}
