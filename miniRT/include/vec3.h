/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:14:08 by chanson           #+#    #+#             */
/*   Updated: 2023/04/23 20:02:05 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include <math.h>

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_color3;
typedef struct s_vec3	t_dir;
typedef struct s_vec3	t_point3;
typedef struct s_vec3x3	t_vec3x3;
typedef struct s_vec3x3	t_rot;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_vec3x3
{
	t_vec3	v_x;
	t_vec3	v_y;
	t_vec3	v_z;
};

t_vec3		vec3init(double x, double y, double z);
t_vec3		add_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		sub_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		mul_vec3(t_vec3 v1, double t);
t_vec3		div_vec3(t_vec3 v1, double t);
double		dot_vec3(t_vec3 v1, t_vec3 v2);
t_vec3		cross_vec3(t_vec3 v1, t_vec3 v2);
double		len_vec3(t_vec3 v1);
double		dotself_vec3(t_vec3 v);
double		ft_pow(double a);
t_vec3		normalize_vec3(t_vec3 v1);
t_vec3x3	mul_vec3x3(t_vec3x3 v1, t_vec3x3 v2);
t_vec3x3	vec3x3init(t_vec3 v_x, t_vec3 v_y, t_vec3 v_z);
t_vec3		vec3x3_x_vec3(t_vec3x3 vec3x3, t_vec3 vec);
t_vec3x3	transpose_vec3x3(t_vec3x3 vec3x3);
t_rot		rotate_vec_001(t_vec3 normal);
double		get_radian(double theta);
t_rot		rotate_vec(double t1, double t2, double t3);
t_vec3		point_symemtry(t_vec3 target, t_vec3 std);
#endif