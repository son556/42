/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:14:45 by chanson           #+#    #+#             */
/*   Updated: 2023/04/22 13:53:25 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	dotself_vec3(t_vec3 v)
{
	return (dot_vec3(v, v));
}

t_vec3x3	vec3x3init(t_vec3 v_x, t_vec3 v_y, t_vec3 v_z)
{
	t_vec3x3	vec3x3;

	vec3x3.v_x = v_x;
	vec3x3.v_y = v_y;
	vec3x3.v_z = v_z;
	return (vec3x3);
}

t_vec3	vec3x3_x_vec3(t_vec3x3 vec3x3, t_vec3 vec)
{
	t_vec3	result;

	result.x = dot_vec3(vec3x3.v_x, vec);
	result.y = dot_vec3(vec3x3.v_y, vec);
	result.z = dot_vec3(vec3x3.v_z, vec);
	return (result);
}

t_vec3x3	transpose_vec3x3(t_vec3x3 vec3x3)
{
	t_vec3x3	vec3x3_t;

	vec3x3_t.v_x = vec3init(vec3x3.v_x.x, vec3x3.v_y.x, vec3x3.v_z.x);
	vec3x3_t.v_y = vec3init(vec3x3.v_x.y, vec3x3.v_y.y, vec3x3.v_z.y);
	vec3x3_t.v_z = vec3init(vec3x3.v_x.z, vec3x3.v_y.z, vec3x3.v_z.z);
	return (vec3x3_t);
}

t_rot	rotate_vec_001(t_vec3 normal)
{
	t_vec3x3	rot_y;
	t_vec3x3	rot_z;
	t_rot		rot;
	t_vec3		rot_e;

	if (normal.x == 0 && normal.y == 0 && normal.z == 1)
	{
		rot.v_x = vec3init(1.0, 0.0, 0.0);
		rot.v_y = vec3init(0.0, 1.0, 0.0);
		rot.v_z = vec3init(0.0, 0.0, 1.0);
		return (rot);
	}
	rot_e.x = sqrt(pow(normal.y, 2) + pow(normal.z, 2));
	rot_e.y = sqrt(pow(normal.x, 2) + pow(normal.y, 2) + pow(normal.z, 2));
	rot_e.z = sqrt(pow(normal.x, 2) + pow(normal.y, 2));
	rot_z.v_x = vec3init(normal.x / rot_e.z, normal.y / rot_e.z, 0);
	rot_z.v_y = vec3init(-normal.y / rot_e.z, normal.x / rot_e.z, 0);
	rot_z.v_z = vec3init(0, 0, 1);
	rot_y.v_x = vec3init(normal.z / rot_e.y, 0, -rot_e.z / rot_e.y);
	rot_y.v_y = vec3init(0, 1, 0);
	rot_y.v_z = vec3init(rot_e.z / rot_e.y, 0, normal.z / rot_e.y);
	rot = mul_vec3x3(rot_y, rot_z);
	return (rot);
}
