/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:42:58 by chanson           #+#    #+#             */
/*   Updated: 2023/05/13 21:16:41 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

t_vec3	vec3_x_vec3(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3	vec;

	vec.x = vec1.x * vec2.x;
	vec.y = vec1.y * vec2.y;
	vec.z = vec1.z * vec2.z;
	return (vec);
}

t_vec3	random_in_unit_sphere(void)
{
	t_vec3	vec;

	while (1)
	{
		vec = random_minmax_vec3(-1, 1);
		if (len_vec3(vec) >= 1)
			continue ;
		return (vec);
	}
}

double	ft_min(double val, double min)
{
	if (val > min)
		return (min);
	return (val);
}
