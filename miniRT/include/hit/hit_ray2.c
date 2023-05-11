/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_ray2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:08:35 by chanson           #+#    #+#             */
/*   Updated: 2023/05/11 20:38:44 by chanson          ###   ########.fr       */
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

static int	obj_arr_hit(t_obj *obj, t_ray ray, t_norm *norm, int n)
{
	t_norm		tmp_n;
	int			i;
	int			m;

	norm->t_max = INFINITY;
	i = -1;
	m = -1;
	while (++i < n)
	{
		if (i == norm->hit_idx)
			continue ;
		tmp_n.t_max = norm->t_max;
		tmp_n = find_hit_function(ray, obj[i], tmp_n.t_max);
		if (tmp_n.root != 0)
		{
			norm->t_max = tmp_n.root;
			norm->n_vec = tmp_n.n_vec;
			norm->root = tmp_n.root;
			norm->hit = ray_at(ray, norm->root);
			m = i;
		}
	}
	norm->hit_idx = m;
	return (m);
}

t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_norm		temp;
	t_color3	col;

	temp = *norm;
	if (norm->depth <= 0)
		return (mul_vec3(norm->color, 0.1));
	if (obj_arr_hit(obj, ray, &temp, n) != -1)
	{
		norm->depth -= 1;
		norm->n_vec = temp.n_vec;
		norm->root = temp.root;
		norm->hit = temp.hit;
		if (norm->depth == norm->p_depth - 1)
			norm->color = obj[temp.hit_idx].color;
		return (mul_vec3(test_color(diffuse_ray(*norm), obj, norm, n), 0.5));
	}
	if (norm->depth == norm->p_depth)
		return (define_background_color(ray));
	norm->light.ratio = dot_vec3(norm->n_vec, \
		normalize_vec3(sub_vec3(norm->light.point, norm->hit)));
	norm->light.ratio = ft_minmax(norm->light.ratio, 0, 1);
	norm->light.ratio = ft_minmax(norm->light.ratio + 0.3, 0, 1);
	col = mul_vec3(norm->color, norm->light.ratio);
	return (col);
}
