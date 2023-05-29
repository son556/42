/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:09:50 by chanson           #+#    #+#             */
/*   Updated: 2023/05/29 20:23:54 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	def_color(t_color3 *col, t_obj *obj, t_norm temp, t_norm norm)
{
	*col = obj[temp.hit_idx].color;
	if (obj[temp.hit_idx].texture == CHECK_TEXTURE)
		*col = texture_color(norm.u, norm.v, temp.hit, *col);
	else if (obj[temp.hit_idx].texture == NOISE_TEXTURE)
		*col = noise_color(temp, 4);
}

static t_ray	def_new_ray(t_ray ray, t_obj *obj, t_norm temp)
{
	t_ray	new_ray;

	if (temp.material == METAL)
		new_ray = specular_ray(temp, ray, obj[temp.hit_idx].fuzz);
	else if (temp.material == GLASS)
		new_ray = refract_ray(temp, ray, obj[temp.hit_idx].ref_idx);
	else
		new_ray = diffuse_ray(temp, ray);
	return (new_ray);
}

t_color3	light_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
{
	t_norm		temp;
	t_color3	col;
	t_ray		new_ray;

	temp = *norm;
	// printf("depth:%d\n", norm->depth);
	if (norm->depth <= 0)
	{
		// printf("0\n");
		return (vec3init(0, 0, 0));
	}
	// printf("hi\n");
	if (obj_arr_hit(obj, ray, &temp, n) != -1)
	{
		// printf("hello\n");
		norm->depth -= 1;
		// printf("1\n");
		if (obj[temp.hit_idx].material == LIGHT)
		{	
			// printf("22\n");
			return (norm->light.color);
		}
		// printf("2\n");
		def_color(&col, obj, temp, *norm);
		// printf("3\n");
		new_ray = def_new_ray(ray, obj, temp);
		// printf("4\n");
		return (vec3_x_vec3(light_color(new_ray, obj, norm, n), col));
	}
	// printf("5\n");
	return (norm->background);
}
