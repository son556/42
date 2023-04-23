/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:21:32 by chanson           #+#    #+#             */
/*   Updated: 2023/04/23 20:44:21 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static double	where_hit_cone(t_discrim disc, t_ray ray, t_cone con, int flag)
{
	double	temp;
	double	t;

	if (flag == 2)
		return (0);
	temp = dot_vec3(sub_vec3(ray_at(ray, disc.root), con.c_h), con.n_vec);
	if (temp >= 0.0 && temp <= con.height)
		return (disc.root);
	else
	{
		if (temp < 0)
		{
			disc.root = disc.root_2;
			t = where_hit_cone(disc, ray, con, ++flag);
		}
		else
		{
			t = -dot_vec3(sub_vec3(ray.point, con.center), con.n_vec) / \
				dot_vec3(ray.direction, con.n_vec);
			temp = len_vec3(sub_vec3(ray_at(ray, t), con.center));
		}
		if (temp > con.radius)
			return (0);
	}
	return (t);
}

static t_bool	line_in_cone(t_cone con, t_ray ray, t_discrim disc)
{
	double	t;

	if (disc.discrim <= 1e-5)
	{
		t = ft_abs(dot_vec3(ray.direction, con.n_vec));
		if (t <= con.cos + 1e-5 && t >= con.cos - 1e-5)
			return (0);
	}
	return (1);
}

static double	hit_cone_(t_cone con, t_ray ray, double t_max, t_discrim disc)
{
	if (!line_in_cone(con, ray, disc))
		return (0);
	disc.root = (-disc.b - sqrt(disc.discrim)) / disc.a;
	if (!range_in_hit(&disc, t_max))
		return (0);
	disc.root = where_hit_cone(disc, ray, con, 0);
	if (disc.root < 1e-5)
		return (0);
	return (disc.root);
}

double	hit_cone(t_cone	con, t_ray ray, double t_max)
{
	t_discrim	disc;
	double		m;

	con.c_h = add_vec3(con.center, mul_vec3(con.n_vec, -con.height));
	con.n_vec = normalize_vec3(sub_vec3(con.center, con.c_h));
	con.cos = ft_pow(con.height) / \
		sqrt(ft_pow(con.height) + ft_pow(con.radius));
	m = ft_pow(con.radius) / ft_pow(con.height);
	disc.ac = sub_vec3(ray.point, con.c_h);
	disc.a = dotself_vec3(ray.direction) - (m + 1) * \
		ft_pow(dot_vec3(ray.direction, con.n_vec));
	disc.b = dot_vec3(ray.direction, disc.ac) - (m + 1) * \
		dot_vec3(ray.direction, con.n_vec) * dot_vec3(disc.ac, con.n_vec);
	disc.c = dotself_vec3(disc.ac) - \
		(m + 1) * ft_pow(dot_vec3(disc.ac, con.n_vec));
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	if (disc.discrim < 0)
		return (0);
	return (hit_cone_(con, ray, t_max, disc));
}
