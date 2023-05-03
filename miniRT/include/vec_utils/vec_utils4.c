/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:34:52 by chanson           #+#    #+#             */
/*   Updated: 2023/04/23 20:01:45 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vec3.h"

double	get_radian(double theta)
{
	return (theta * (M_PI / 180));
}

t_rot	rotate_vec(double t1, double t2, double t3)
{
	t_rot	rot_1;
	t_rot	rot_2;
	double	roll;
	double	pitch;
	double	yaw;

	roll = get_radian(t1);
	pitch = get_radian(t2);
	yaw = get_radian(t3);
	rot_1.v_x = vec3init(cos(yaw), -sin(yaw), 0);
	rot_1.v_y = vec3init(sin(yaw), cos(yaw), 0);
	rot_1.v_z = vec3init(0, 0, 1);
	rot_2.v_x = vec3init(cos(pitch), 0, -sin(pitch));
	rot_2.v_y = vec3init(0, 1, 0);
	rot_2.v_z = vec3init(sin(pitch), 0, cos(pitch));
	rot_1 = mul_vec3x3(rot_1, rot_2);
	rot_2.v_x = vec3init(1, 0, 0);
	rot_2.v_y = vec3init(0, cos(roll), -sin(roll));
	rot_2.v_z = vec3init(0, sin(roll), cos(roll));
	return (mul_vec3x3(rot_1, rot_2));
}

double	ft_pow(double a)
{
	return (a * a);
}

t_vec3	point_symemtry(t_vec3 target, t_vec3 std)
{
	t_vec3	move;

	move.x = std.x - (target.x - std.x);
	move.y = std.y - (target.y - std.y);
	move.z = std.z - (target.z - std.z);
	return (move);
}