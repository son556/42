/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:30:49 by chanson           #+#    #+#             */
/*   Updated: 2023/04/09 21:30:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./mlx/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "math_ft.h"
# include <stdlib.h>
# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	orig;
	t_vec3	dir;
}	t_ray;

t_vec3	*vec3_init(double x, double y, double z);
t_vec3	*vec3_add(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec3_minus(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec3_times(double t, t_vec3 *v);
t_vec3	*vec3_div(double t, t_vec3 *v);
double	vec3_dot(t_vec3 *v1, t_vec3 *v2);
t_vec3  *vec3_cross(t_vec3 *u, t_vec3 *v);
double	vec3_len(t_vec3 *v);
t_vec3	*vec3_unit(t_vec3 *v);
t_ray	*set_ray(t_vec3 *orig, t_vec3 *dir);
t_vec3	*point_at(double t, t_ray *ray);
#endif