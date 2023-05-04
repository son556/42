/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:06:26 by chanson           #+#    #+#             */
/*   Updated: 2023/05/04 19:56:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	where_hit_cylinder_(t_vec3 *p, t_norm *n, t_cylinder c, double temp)
{
	if (temp > c.height)
	{
		n->n_vec = c.n_vec;
		*p = c.c_h;
	}
	else
	{
		n->n_vec = mul_vec3(c.n_vec, -1);
		*p = c.c_c;
	}
}

static double	where_hit_cylinder(t_discrim disc, t_ray ray, \
	t_cylinder cyl, t_norm *norm)
{
	double	temp;
	double	t;
	t_vec3	plane;

	plane = ray_at(ray, disc.root);
	temp = dot_vec3(sub_vec3(plane, cyl.c_c), cyl.n_vec);
	norm->n_vec = sub_vec3(plane, add_vec3(cyl.c_c, mul_vec3(cyl.n_vec, temp)));
	if (temp >= 0.0 && temp <= cyl.height)
		return (disc.root);
	else
	{
		where_hit_cylinder_(&plane, norm, cyl, temp);
		t = dot_vec3(ray.direction, cyl.n_vec);
		if (t >= -1e-5 && t <= 1e-5)
			return (0);
		t = -dot_vec3(sub_vec3(ray.point, plane), cyl.n_vec) / \
			dot_vec3(ray.direction, cyl.n_vec);
		if (t < 0 || t > norm->root)
			return (0);
		temp = len_vec3(sub_vec3(ray_at(ray, t), plane));
		if (temp > cyl.radius)
			return (0);
	}
	return (t);
}

int	range_in_hit(t_discrim *disc, double t_max)
{
	disc->root = (-disc->b - sqrt(disc->discrim)) / disc->a;
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

t_norm	hit_cylinder(t_cylinder cyl, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	norm.root = 0;
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
		return (norm);
	if (disc.discrim <= 1e-5)
		if (ft_abs(dot_vec3(ray.direction, cyl.n_vec)) >= 1 - 1e-5)
			return (norm);
	if (!range_in_hit(&disc, t_max))
		return (norm);
	norm.root = t_max;
	norm.root = where_hit_cylinder(disc, ray, cyl, &norm);
	return (norm);
}
