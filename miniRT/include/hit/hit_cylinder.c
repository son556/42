/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:06:26 by chanson           #+#    #+#             */
/*   Updated: 2023/04/23 19:49:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static double	where_hit_cylinder(t_discrim disc, t_ray ray, t_cylinder cyl)
{
	double	temp;
	double	t;
	t_vec3	plane;

	temp = dot_vec3(sub_vec3(ray_at(ray, disc.root), cyl.c_c), cyl.n_vec);
	if (temp >= 0.0 && temp <= cyl.height)
		return (disc.root);
	else
	{
		if (temp > cyl.height)
			plane = cyl.c_h;
		else
			plane = cyl.c_c;
		t = dot_vec3(ray.direction, cyl.n_vec);
		if (t >= -1e-5 && t <= 1e-5)
			return (0);
		t = -dot_vec3(sub_vec3(ray.point, plane), cyl.n_vec) / \
			dot_vec3(ray.direction, cyl.n_vec);
		temp = len_vec3(sub_vec3(ray_at(ray, t), plane));
		if (temp > cyl.radius)
			return (0);
	}
	return (t);
}

int	range_in_hit(t_discrim *disc, double t_max)
{
	disc->root = (-disc->b - sqrt(disc->discrim)) / disc->a;
	disc->root_2 = (-disc->b + sqrt(disc->discrim)) / disc->a;
	if (disc->root < 0 || disc->root > t_max)
	{
		disc->root = (-disc->b + sqrt(disc->discrim)) / disc->a;
		if (disc->root < 0 || disc->root > t_max)
			return (0);
	}
	return (1);
}

double	ft_abs(double num)
{
	if (num < 0)
		return (-1 * num);
	return (num);
}

double	hit_cylinder(t_cylinder cyl, t_ray ray, double t_max)
{
	t_discrim	disc;

	cyl.c_h = add_vec3(cyl.center, mul_vec3(cyl.n_vec, cyl.height / 2));
	cyl.c_c = sub_vec3(cyl.center, mul_vec3(cyl.n_vec, cyl.height / 2));
	disc.ac = sub_vec3(ray.point, cyl.c_c);
	disc.a = dotself_vec3(ray.direction) - \
		ft_pow(dot_vec3(ray.direction, cyl.n_vec));
	disc.b = dot_vec3(ray.direction, disc.ac) - \
		(dot_vec3(ray.direction, cyl.n_vec) * dot_vec3(disc.ac, cyl.n_vec));
	disc.c = dotself_vec3(disc.ac) - ft_pow(dot_vec3(disc.ac, cyl.n_vec)) - \
		ft_pow(cyl.radius);
	disc.discrim = disc.b * disc.b - disc.a * disc.c;
	if (disc.discrim < 0)
		return (0);
	if (disc.discrim <= 1e-5)
		if (ft_abs(dot_vec3(ray.direction, cyl.n_vec)) >= 1 - 1e-5)
			return (0);
	if (!range_in_hit(&disc, t_max))
		return (0);
	disc.root = where_hit_cylinder(disc, ray, cyl);
	if (disc.root < 1e-5)
		return (0);
	return (disc.root);
}
