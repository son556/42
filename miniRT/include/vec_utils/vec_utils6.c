/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:02:47 by chanson           #+#    #+#             */
/*   Updated: 2023/05/09 20:42:46 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	random_0_to_1(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_min_max(double min, double max)
{
	return (min + (max - min) * random_0_to_1());
}

t_vec3	vec3_rand(void)
{
	t_vec3	random_vec3;

	random_vec3 = vec3init(random_0_to_1(), random_0_to_1(), random_0_to_1());
	return (random_vec3);
}

t_vec3	minmax_vec3(t_vec3 vec, double min, double max)
{
	t_vec3	vec3;

	vec3.x = ft_minmax(vec.x, min, max);
	vec3.y = ft_minmax(vec.y, min, max);
	vec3.z = ft_minmax(vec.z, min, max);
	return (vec3);
}
