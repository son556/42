/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:02:47 by chanson           #+#    #+#             */
/*   Updated: 2023/05/08 20:24:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	random_0_to_1(void)
{
	srand(time(NULL));
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
