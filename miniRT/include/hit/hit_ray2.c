/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:08:35 by chanson           #+#    #+#             */
/*   Updated: 2023/05/09 20:54:26 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_vec3	color;
	int		i;
	double	temp;
	t_norm	tmp_n;

	tmp_n.t_max = INFINITY;
	temp = tmp_n.t_max;
	i = -1;
	color.x = -1000;
	while (++i < n)
	{
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		tmp_n.t_max = temp;
		if (tmp_n.root > 0.0)
		{
			norm->root = tmp_n.root;
			norm->n_vec = tmp_n.n_vec;
			norm->hit = ray_at(ray, norm->root);
			norm->front = front_or_back(ray, *norm);
			if (norm->front == 0)
				norm->n_vec = mul_vec3(norm->n_vec, -1);
			norm->light.ratio = dot_vec3(norm->n_vec, \
				normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
			norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
			norm->light.ratio += 0.3;
			if (norm->light.ratio > 1)
				norm->light.ratio = 1;
			color = mul_vec3(obj[i].color, norm->light.ratio);
			norm->t_max = tmp_n.root;
			temp = tmp_n.root;
			tmp_n.t_max = temp;
			if (shade(*norm, obj, n, i))
				color = mul_vec3(obj[i].color, 0.3);
		}
	}
	if (color.x == -1000)
	{
		norm->root = 0.5 * (ray.direction.y + 1.0);
		color = vec3init(1.0 - 0.5 * norm->root, 1.0 - 0.3 * norm->root, 1.0);
	}
	return (color);
}
