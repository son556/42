/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:52:24 by chanson           #+#    #+#             */
/*   Updated: 2023/04/29 21:41:21 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

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
