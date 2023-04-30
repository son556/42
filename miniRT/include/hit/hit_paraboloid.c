/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/04/30 20:17:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	find_norm(t_norm *no, t_para para, t_ray ray)
{
	t_vec3	hit;
	t_vec3	hit_;
	t_vec3	mid;
	t_vec3	cro1;

	if (dot_vec3(ray_at(ray, no->root), \
		normalize_vec3(sub_vec3(para.pl.center, para.cen))) > para.len)
		no->n_vec = normalize_vec3(sub_vec3(para.pl.center, para.cen));
	else
	{
		hit = ray_at(ray, no->root);
		hit_ = add_vec3(hit, mul_vec3(mul_vec3(para.pl.n_vec, -1), no->root));
		mid = mul_vec3(add_vec3(hit_, para.cen), 0.5);
		cro1 = cross_vec3(sub_vec3(hit_, hit), sub_vec3(para.cen, hit));
		no->n_vec = cross_vec3(sub_vec3(mid, hit), cro1);
		no->n_vec = normalize_vec3(no->n_vec);
	}
}

static int	validation_para(t_discrim d, t_ray ray, t_para para, double t_max)
{
	double	num;
	t_vec3	h;

	if (d.discrim < 0)
		return (0);
	if (range_in_hit(&d, t_max) == 0)
		return (0);
	num = dot_vec3(normalize_vec3(sub_vec3(para.pl.center, para.cen)), \
		sub_vec3(ray_at(ray, d.root), para.cen));
	if (num > 0 && ft_abs(num) > (para.len_cc / 2.0))
		return (0);
	if (num < 0 && ft_abs(num) > para.len - (para.len_cc / 2.0))
	{
		num = para.len - para.len_cc / 2.0;
		h = add_vec3(para.cen, mul_vec3(para.pl.n_vec, num));
		num = -1 * dot_vec3(sub_vec3(ray.point, h), \
			mul_vec3(para.pl.n_vec, -1)) / \
			dot_vec3(mul_vec3(para.pl.n_vec, -1), ray.direction);
		num = len_vec3(sub_vec3(ray_at(ray, num), h));
		if (num > para.r)
			return (0);
	}
	return (1);
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
	if (validation_para(disc, ray, para, t_max) == 0)
		return (norm);
	norm.root = disc.root;
	find_norm(&norm, para, ray);
	return (norm);
}

double	paraboloid_r(t_para	para)
{
	double	r;

	r = sqrt(2 * para.len * para.len_cc);
	return (r);
}