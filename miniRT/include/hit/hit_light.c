/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:20:45 by chanson           #+#    #+#             */
/*   Updated: 2023/05/25 19:46:34 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	diffuse_light(t_norm *norm, t_color3 col)
{
	norm->light.color = col;
}

// t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n)
// {
// 	t_norm		temp;
// 	t_color3	col;
// 	t_ray		new_ray;

// 	temp = *norm;
// 	if (norm->depth <= 0)
// 		return (vec3init(0, 0, 0));
// 	if (obj_arr_hit(obj, ray, &temp, n) == -1)
// 		return norm->background;
// 	if (obj_arr_hit(obj, ray, &temp, n) != -1)
// 	{
// 		norm->depth -= 1;
// 		col = obj[temp.hit_idx].color;
// 		if (obj[temp.hit_idx].texture == CHECK_TEXTURE)
// 			col = texture_color(norm->u, norm->v, temp.hit, col);
// 		else if (obj[temp.hit_idx].texture == NOISE_TEXTURE)
// 			col = noise_color(temp, 4);
// 		if (temp.material == METAL)
// 			new_ray = specular_ray(temp, ray, obj[temp.hit_idx].fuzz);
// 		else if (temp.material == GLASS)
// 			new_ray = refract_ray(temp, ray, obj[temp.hit_idx].ref_idx);
// 		else
// 			new_ray = diffuse_ray(temp, ray);
// 		return (vec3_x_vec3(test_color(new_ray, obj, norm, n), col));
// 	}
// 	return (define_background_color(ray));
// }
