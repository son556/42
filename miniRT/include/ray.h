/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:20:15 by chanson           #+#    #+#             */
/*   Updated: 2023/04/18 13:25:57 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

typedef struct s_ray	t_ray;

struct s_ray
{
	t_point3	point;
	t_dir		direction;
};

t_ray		ray_init(t_point3 point, t_dir direction);
t_point3	ray_at(t_ray ray, double t);
#endif