/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:21:32 by chanson           #+#    #+#             */
/*   Updated: 2023/04/29 15:33:27 by chanson          ###   ########.fr       */
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
			t = where_hit_cone(disc, ray, con, ++flag);
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

static t_norm	hit_cone_(t_cone con, t_ray ray, double t_max, t_discrim disc)
{
	t_norm	norm;
	double	discrim;
	t_vec3	hit;

	norm.root = 0;
	if (!line_in_cone(con, ray, disc))
		return (norm);
	disc.root = (-disc.b - sqrt(disc.discrim)) / disc.a;
	if (!range_in_hit(&disc, t_max))
		return (norm);
	disc.root = where_hit_cone(disc, ray, con, 0);
	if (disc.root < 1e-5)
		return (norm);
	norm.root = disc.root;
	hit = ray_at(ray, norm.root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	discrim = dot_vec3(sub_vec3(con.center, con.c_h), hit);
	norm.n_vec = sub_vec3(add_vec3(mul_vec3(hit, discrim), con.c_h), \
		con.center);
	norm.n_vec = normalize_vec3(norm.n_vec);
	discrim = dot_vec3(sub_vec3(hit, con.center), con.n_vec);
	if (discrim == 0.0)
		norm.n_vec = con.n_vec;
	return (norm);
}

t_norm	hit_cone(t_cone	con, t_ray ray, double t_max)
{
	t_discrim	disc;
	double		m;
	t_norm		norm;

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
	norm.root = 0;
	if (disc.discrim < 0)
		return (norm);
	return (hit_cone_(con, ray, t_max, disc));
}
