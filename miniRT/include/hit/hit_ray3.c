/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:23:20 by chanson           #+#    #+#             */
/*   Updated: 2023/05/13 21:14:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static t_vec3	refract_dir(t_vec3 ray_dir, t_vec3 n_vec, double ref_idx)
{
	double	cos_theta;
	t_vec3	r_out_perp;
	t_vec3	r_out_parallel;
	t_vec3	refract_dir;

	cos_theta = ft_min(dot_vec3(mul_vec3(ray_dir, -1), n_vec), 1.0);
	r_out_perp = add_vec3(ray_dir, mul_vec3(n_vec, cos_theta));
	r_out_perp = mul_vec3(r_out_perp, ref_idx);
	r_out_parallel = mul_vec3(n_vec, -1 * sqrt(ft_abs(1 - \
		ft_pow(len_vec3(r_out_perp)))));
	refract_dir = add_vec3(r_out_perp, r_out_parallel);
	refract_dir = normalize_vec3(refract_dir);
	return (refract_dir);
}

t_ray	refract_ray(t_norm norm, t_ray ray, double ref_idx)
{
	t_ray	new_ray;

	new_ray.point = norm.hit;
	if (norm.front)
		ref_idx = 1.0 / ref_idx;
	new_ray.direction = refract_dir(ray.direction, norm.n_vec, ref_idx);
	return (new_ray);
}
