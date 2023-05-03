/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:41 by chanson           #+#    #+#             */
/*   Updated: 2023/05/01 19:45:02 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
			return (0);
			// t = where_hit_cone(disc, ray, con, ++flag);
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

t_norm	hit_paraboloid(t_para para, t_ray ray, double t_max)
{
	t_norm		norm;
	t_discrim	disc;

	norm.root = 0;
	disc.a = ft_pow(dot_vec3(para.pl.n_vec, ray.direction));
	disc.a -= dotself_vec3(ray.direction);
	disc.b = dot_vec3(ray.direction, para.pl.n_vec);
	disc.b *= dot_vec3(ray.point, para.pl.n_vec);
	disc.b -= dot_vec3(ray.direction, para.pl.n_vec) * \
		dot_vec3(para.pl.center, para.pl.n_vec);
	disc.b += dot_vec3(ray.direction, para.cen);
	disc.c = dot_vec3(ray.point, para.pl.n_vec) - \
		dot_vec3(para.pl.center, para.pl.n_vec);
	disc.c = ft_pow(disc.c) - dotself_vec3(para.cen) - \
		2 * dot_vec3(ray.point, ray.direction);
	disc.c -= dotself_vec3(ray.point);
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	if (disc.discrim < 0)
		return (norm);
	if (range_in_hit(&disc, t_max) == 0)
		return (norm);
	if (ft_abs(dot_vec3(normalize_vec3(sub_vec3(para.pl.center, para.cen)), \
		sub_vec3(ray_at(ray, disc.root), para.cen))) > para.len)
		return (norm);
	norm.root = disc.root;
	return (norm);
}


//------------------------------------- cone ------------------------------------

#include "../hit.h"

static double	where_hit_cone(t_discrim disc, t_ray ray, t_cone con, \
	t_norm *norm)
{
	double	temp;
	double	t;
	t_vec3	hit;

	hit = ray_at(ray, disc.root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	hit = add_vec3(con.c_h, mul_vec3(hit, con.height * con.c_cos));
	norm->n_vec = normalize_vec3(sub_vec3(hit, con.center));
	temp = dot_vec3(sub_vec3(ray_at(ray, disc.root), con.c_h), con.n_vec);
	if (temp >= 0.0 && temp <= con.height)
		return (disc.root);
	else
	{
		t = -dot_vec3(sub_vec3(ray.point, con.center), \
			mul_vec3(con.n_vec, -1)) / dot_vec3(ray.direction, con.n_vec);
		temp = len_vec3(sub_vec3(ray_at(ray, t), con.center));
		norm->n_vec = con.n_vec;
		if (temp > con.radius)
			return (0);
	}
	return (t);
}

static t_bool	line_in_cone(t_cone con, t_ray ray, t_discrim *disc)
{
	double	t;
	t_vec3	hit;

	disc->root = (-disc->b - sqrt(ft_pow(disc->b) - \
			disc->a * disc->c)) / disc->a;
	hit = ray_at(ray, disc->root);
	hit = normalize_vec3(sub_vec3(hit, con.c_h));
	t = dot_vec3(hit, con.n_vec);
	if (t <= con.c_cos + 1e-5 && t >= con.c_cos - 1e-5)
		return (1);
	if (t < 0)
	{
		disc->root = (-disc->b + sqrt(ft_pow(disc->b) - \
			disc->a * disc->c)) / disc->a;
		hit = ray_at(ray, disc->root);
		hit = normalize_vec3(sub_vec3(hit, con.c_h));
		t = dot_vec3(hit, con.n_vec);
		if (t <= con.c_cos + 1e-5 && t >= con.c_cos - 1e-5)
			return (1);
	}
	return (0);
}

static t_norm	hit_cone_(t_cone con, t_ray ray, double t_max, t_discrim disc)
{
	t_norm	norm;

	norm.root = 0;
	if (!line_in_cone(con, ray, &disc))
		return (norm);
	if (disc.root < 0 || disc.root > t_max)
		return (norm);
	disc.root = where_hit_cone(disc, ray, con, &norm);
	if (disc.root < 1e-5)
		return (norm);
	norm.root = disc.root;
	return (norm);
}

t_norm	hit_cone(t_cone	con, t_ray ray, double t_max)
{
	t_discrim	disc;
	double		m;
	t_norm		norm;
	t_cone		con2;

	con2 = con;
	con2.c_h = add_vec3(con2.center, mul_vec3(con2.n_vec, con2.height));
	con2.n_vec = normalize_vec3(sub_vec3(con2.center, con2.c_h));
	con2.c_cos = con2.height / \
		sqrt(ft_pow(con2.height) + ft_pow(con2.radius));
	m = ft_pow(con2.radius) / ft_pow(con2.height);
	disc.ac = sub_vec3(ray.point, con2.c_h);
	disc.a = dotself_vec3(ray.direction) - (m + 1) * \
		ft_pow(dot_vec3(ray.direction, con2.n_vec));
	disc.b = dot_vec3(ray.direction, disc.ac) - (m + 1) * \
		dot_vec3(ray.direction, con2.n_vec) * dot_vec3(disc.ac, con2.n_vec);
	disc.c = dotself_vec3(disc.ac) - \
		(m + 1) * ft_pow(dot_vec3(disc.ac, con2.n_vec));
	disc.discrim = ft_pow(disc.b) - disc.a * disc.c;
	norm.root = 0;
	if (disc.discrim < 0)
		return (norm);
	return (hit_cone_(con2, ray, t_max, disc));
}
