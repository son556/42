/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:32:16 by chanson           #+#    #+#             */
/*   Updated: 2023/04/09 21:06:30 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*vec3_init(double x, double y, double z)
{
	t_vec3	*vec3;

	vec3 = (t_vec3 *)malloc(sizeof(t_vec3));
	vec3->x = x;
	vec3->y = y;
	vec3->z = z;
	return (vec3);
}

t_vec3	*vec3_add(t_vec3 *v1, t_vec3 *v2)
{
	return (vec3_init(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vec3	*vec3_minus(t_vec3 *v1, t_vec3 *v2)
{
	return (vec3_init(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_vec3	*vec3_times(double t, t_vec3 *v)
{
	return (vec3_init(v->x * t, v->y * t, v->z * t));
}

t_vec3	*vec3_div(double t, t_vec3 *v)
{
	return (vec3_init(v->x / t, v->y / t, v->z / t));
}

double	vec3_dot(t_vec3 *v1, t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3  *vec3_cross(t_vec3 *u, t_vec3 *v)
{
	double	x;
	double	y;
	double	z;

	x = u->y * v->z - u->z * v->y;
	y = u->z * v->x - u->x * v->z;
	z = u->x * v->y - u->y * v->x;
	return (vec3_init(x, y, z));
}

double	vec3_len(t_vec3 *v)
{
	double	result;

	result = pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2);
	return (sqrt(result));
}

t_vec3 *vec3_unit(t_vec3 *v)
{
	return (vec3_div(vec3_len(v), v));
}
