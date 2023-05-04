/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/05/04 21:13:44 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"
#include <stdio.h>

static void	find_norm(t_norm *no, t_para para, t_vec3 hit, t_discrim *d)
{
	t_vec3	mid;
	t_vec3	hit2;
	double	t;

	no->root = d->root;
	t = dot_vec3(sub_vec3(para.pl.center, hit), para.pl.n_vec);
	hit2 = add_vec3(hit, mul_vec3(mul_vec3(para.pl.n_vec, -1), t));
	mid = mul_vec3(add_vec3(para.cen, hit2), 0.5);
	no->n_vec = normalize_vec3(sub_vec3(mid, para.cen));
}

static t_norm	validation_para(t_discrim *d, t_ray ray, t_para p, double t_max)
{
	t_vec3	h;
	t_norm	norm;

	norm.root = 0;
	norm.n_vec.x = dot_vec3(mul_vec3(p.pl.n_vec, -1), \
		sub_vec3(ray_at(ray, d->root), p.cen));
	if (norm.n_vec.x < 0 && ft_abs(norm.n_vec.x) > p.len - (p.len_cc / 2.0))
	{
		h = add_vec3(p.cen, mul_vec3(p.pl.n_vec, p.len - p.len_cc / 2.0));
		norm.n_vec.x = dot_vec3(p.pl.n_vec, ray.direction);
		if (norm.n_vec.x < 1e-5 && norm.n_vec.x > -1e-5)
			return (norm);
		norm.n_vec.x = -1 * dot_vec3(sub_vec3(ray.point, h), p.pl.n_vec) / \
			norm.n_vec.x;
		if (norm.n_vec.x < 0 || norm.n_vec.x > t_max)
			return (norm);
		if (len_vec3(sub_vec3(ray_at(ray, norm.n_vec.x), h)) > p.r)
			return (norm);
		norm.root = norm.n_vec.x;
		norm.n_vec = p.pl.n_vec;
	}
	else
		find_norm(&norm, p, ray_at(ray, norm.root), d);
	return (norm);
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
	norm = validation_para(&disc, ray, para, t_max);
	return (norm);
}

double	paraboloid_r(t_para	para)
{
	double	r;

	r = sqrt(2 * para.len * para.len_cc);
	return (r);
}

void	complete_para(t_para *para, t_vec3 center, t_vec3 move, double len)
{
	para->cen = center;
	para->pl.center = sub_vec3(para->cen, move);
	para->pl.n_vec = normalize_vec3(sub_vec3(para->cen, para->pl.center));
	para->len = len;
	para->len_cc = len_vec3(sub_vec3(para->cen, para->pl.center));
	para->r = paraboloid_r(*para);
}
