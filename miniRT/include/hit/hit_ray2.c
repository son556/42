/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:08:35 by chanson           #+#    #+#             */
/*   Updated: 2023/05/10 21:28:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static t_color3	def_norm(t_norm *norm, t_norm temp, t_ray ray, t_obj obj)
{
	t_color3	color;

	norm->root = temp.root;
	norm->n_vec = temp.n_vec;
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
	color = mul_vec3(obj.color, norm->light.ratio);
	norm->t_max = temp.root;
	return (color);
}

static t_color3	define_background_color(t_ray ray)
{
	double		t;
	t_color3	color;

	t = 0.5 * (ray.direction.y + 1.0);
	color = vec3init(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0);
	return (color);
}

t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_vec3	color;
	int		i;
	t_norm	tmp_n;

	tmp_n.t_max = INFINITY;
	norm->t_max = tmp_n.t_max;
	i = -1;
	color.x = -1000;
	tmp_n = *norm;
	while (++i < n)
	{
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		tmp_n.t_max = norm->t_max;
		if (tmp_n.root > 0.0)
		{
			color = def_norm(norm, tmp_n, ray, obj[i]);
			tmp_n.t_max = norm->t_max;
			if (shade(*norm, obj, n, i))
				color = mul_vec3(obj[i].color, 0.3);
		}
	}
	if (color.x == -1000)
		color = define_background_color(ray);
	return (color);
}

static t_color3	obj_arr_hit(t_obj *obj, t_ray ray, t_norm *norm, int n)
{
	t_norm		tmp_n;
	int			i;
	t_color3	col;

	norm->t_max = INFINITY;
	i = -1;
	col.x = -1000;
	while (++i < n)
	{
		tmp_n.t_max = norm->t_max;
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		if (tmp_n.root != 0)
		{
			norm->t_max = tmp_n.root;
			norm->n_vec = tmp_n.n_vec;
			norm->root = tmp_n.root;
			norm->hit = ray_at(ray, norm->root);
			col = obj[i].color;
			norm->root = tmp_n.root;
		}
	}
	return (col);
}

t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_color3	col;
	t_norm		temp;

	if (norm->depth <= 0)
		return (vec3init(0, 0, 0));
	col = obj_arr_hit(obj, ray, &temp, n);
	if (col.x != -1000)
	{
		norm->depth -= 1;
		temp.color = norm->color;
		temp.depth = norm->depth;
		temp.light = norm->light;
		*norm = temp;
		if (norm->depth == 29)
			norm->color = col;
		return (mul_vec3(test_color(diffuse_ray(temp), obj, norm, n), 0.5));
	}
	if (norm->depth == 30)
		return (define_background_color(ray));
	norm->light.ratio = dot_vec3(norm->n_vec, \
		normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
	norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
	norm->light.ratio += 0.3;
	if (norm->light.ratio > 1)
		norm->light.ratio = 1;
	col = mul_vec3(norm->color, norm->light.ratio);
	return (col);
}
