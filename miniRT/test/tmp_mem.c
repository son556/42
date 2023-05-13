/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_mem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:41 by chanson           #+#    #+#             */
/*   Updated: 2023/05/13 17:50:33 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../hit.h"
#include <stdio.h>

t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_norm		temp;
	t_color3	col;
	t_ray		new_ray;

	temp = *norm;
	if (norm->depth <= 0)
		return (vec3init(0, 0, 0));
	if (obj_arr_hit(obj, ray, &temp, n) != -1)
	{
		norm->depth -= 1;
		norm->n_vec = temp.n_vec;
		norm->root = temp.root;
		norm->hit = temp.hit;
		norm->hit_idx = temp.hit_idx;
		norm->material = temp.material;
		// if (norm->depth == norm->p_depth - 1)
		// 	norm->color = obj[temp.hit_idx].color;
		col = obj[temp.hit_idx].color;
		if (norm->material == METAL)
			new_ray = specular_ray(*norm, ray);
		else
			new_ray = diffuse_ray(*norm, ray);
		return (vec3_x_vec3(test_color(new_ray, obj, norm, n), col));
	}
	if (norm->depth == norm->p_depth)
		return (define_background_color(ray));
	// norm->light.ratio = dot_vec3(norm->n_vec, \
	// 	normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
	// norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
	// norm->light.ratio = ft_minmax(norm->light.ratio + 0.3, 0, 1);
	// col = mul_vec3(norm->color, norm->light.ratio);
    double t = 0.5*(ray.direction.y + 1.0);
    return add_vec3(mul_vec3(vec3init(1.0, 1.0, 1.0), (1.0 - t)), \
		mul_vec3(vec3init(0.5, 0.7, 1.0), t));
	return (norm->color);
}
