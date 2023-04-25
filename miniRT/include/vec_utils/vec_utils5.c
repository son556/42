/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:59:06 by chanson           #+#    #+#             */
/*   Updated: 2023/04/25 14:25:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

t_vec3x3	vec3x3_x_double(t_vec3x3 vec, double t)
{
	t_vec3x3	mat;

	mat.v_x = mul_vec3(vec.v_x, t);
	mat.v_y = mul_vec3(vec.v_y, t);
	mat.v_y = mul_vec3(vec.v_y, t);
	return (mat);
}

static t_vec3x3	make_factro_matrix(t_inverse_factor factor)
{
	t_vec3x3	mat;

	mat.v_x = vec3init(factor.c_11, factor.c_12, factor.c_13);
	mat.v_y = vec3init(factor.c_21, factor.c_22, factor.c_23);
	mat.v_z = vec3init(factor.c_31, factor.c_32, factor.c_33);
	return (mat);
}

t_vec3x3	inverse_vec3x3(t_vec3x3 vec)
{
	t_vec3x3			inv;
	t_inverse_factor	factor;

	factor.det_a = vec.v_x.x * (vec.v_y.y * vec.v_z.z - vec.v_z.y * vec.v_y.z);
	factor.det_a -= vec.v_x.y * (vec.v_y.x * vec.v_z.z - vec.v_x.z * vec.v_z.x);
	factor.det_a += vec.v_x.z * (vec.v_y.x * vec.v_z.y - vec.v_x.y * vec.v_z.x);
	factor.c_11 = vec.v_y.y * vec.v_z.z - vec.v_z.y * vec.v_y.z;
	factor.c_12 = -1 * (vec.v_x.y * vec.v_z.z - vec.v_z.y * vec.v_x.z);
	factor.c_13 = vec.v_x.y * vec.v_y.z - vec.v_y.y * vec.v_x.z;
	factor.c_21 = -1 * (vec.v_y.x * vec.v_z.z - vec.v_z.x * vec.v_y.z);
	factor.c_22 = vec.v_x.x * vec.v_z.z - vec.v_z.x * vec.v_x.z;
	factor.c_23 = -1 * (vec.v_x.x * vec.v_y.z - vec.v_y.x * vec.v_x.z);
	factor.c_31 = vec.v_y.x * vec.v_z.y - vec.v_z.x * vec.v_y.y;
	factor.c_32 = -1 * (vec.v_x.x * vec.v_z.y - vec.v_z.x * vec.v_x.y);
	factor.c_33 = vec.v_x.x * vec.v_y.y - vec.v_y.x * vec.v_x.y;
	inv = make_factro_matrix(factor);
	inv = transpose_vec3x3(inv);
	inv = vec3x3_x_double(inv, 1 / factor.det_a);
	return (inv);
}

void	display_vec3(t_vec3 vec)
{
	printf("%f %f %f\n", vec.x, vec.y, vec.z);
}
