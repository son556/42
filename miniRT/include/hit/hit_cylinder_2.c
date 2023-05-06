/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:10:53 by chanson           #+#    #+#             */
/*   Updated: 2023/05/06 18:27:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static t_norm	plane_c_h(t_cylinder c, t_ray r, double t_max, t_discrim d)
{
	t_norm	norm;
	t_vec3	hit;
	double	t;

	norm.root = 0;
	hit = ray_at(r, d.b);
	t = d.b;
	if (t < 0 || t > t_max)
	{
		t = d.c;
		hit = ray_at(r, t);
		if (t < 0 || t > t_max)
			return (norm);
		if (len_vec3(sub_vec3(hit, c.c_c)) > c.radius)
			return (norm);
		norm.root = t;
		norm.n_vec = mul_vec3(c.n_vec, -1);
		return (norm);
	}
	if (len_vec3(sub_vec3(hit, c.c_h)) > c.radius)
		return (norm);
	norm.root = t;
	norm.n_vec = c.n_vec;
	return (norm);
}

static t_norm	plane_c_c(t_cylinder c, t_ray r, double t_max, t_discrim d)
{
	t_norm	norm;
	t_vec3	hit;
	double	t;

	norm.root = 0;
	hit = ray_at(r, d.c);
	t = d.c;
	if (t < 0 || t > t_max)
	{
		t = d.b;
		hit = ray_at(r, t);
		if (t < 0 || t > t_max)
			return (norm);
		if (len_vec3(sub_vec3(hit, c.c_h)) > c.radius)
			return (norm);
		norm.root = t;
		norm.n_vec = c.n_vec;
		return (norm);
	}
	if (len_vec3(sub_vec3(hit, c.c_c)) > c.radius)
		return (norm);
	norm.root = t;
	norm.n_vec = mul_vec3(c.n_vec, -1);
	return (norm);
}

t_norm	hit_cylinder(t_cylinder cyl, t_ray ray, double t_max)
{
	t_discrim	disc;
	t_norm		norm;

	norm.root = 0;
	disc.a = dot_vec3(cyl.n_vec, vec3init(0, 0, 1));
	cyl.c_h = add_vec3(cyl.center, mul_vec3(cyl.n_vec, cyl.height * 0.5));
	cyl.c_c = sub_vec3(cyl.center, mul_vec3(cyl.n_vec, cyl.height * 0.5));
	if (disc.a == 1.0 || disc.a == -1.0)
	{
		disc.a = dot_vec3(cyl.n_vec, ray.direction);
		if (disc.a < 1e-5 && disc.a > -1e-5)
			return (norm);
		disc.b = -dot_vec3(sub_vec3(ray.point, cyl.c_h), cyl.n_vec) / disc.a;
		disc.c = -dot_vec3(sub_vec3(ray.point, cyl.c_c), cyl.n_vec) / disc.a;
		if (disc.b < disc.c)
			return (plane_c_h(cyl, ray, t_max, disc));
		else
			return (plane_c_c(cyl, ray, t_max, disc));
	}
	return (hit_cylinder_2(cyl, ray, t_max));
}