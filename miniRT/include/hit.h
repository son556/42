/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:11 by chanson           #+#    #+#             */
/*   Updated: 2023/04/29 21:33:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

# include "vec3.h"
# include "ray.h"
# include <stdlib.h>
# include <math.h>

typedef int				t_bool;

enum e_objects
{
	SPHERE,
	CYLINDER,
	PLANE,
	CUBE,
	CONE,
	PARABOLOID
};

typedef struct s_triangle
{
	t_vec3	n1;
	t_vec3	n2;
	t_vec3	n3;
	t_vec3	n_vec;
}	t_tri;

typedef struct s_cube_plane
{
	t_vec3	center;
	t_vec3	n_vec;
	double	length;
	t_vec3	plane_vertex[4];
	t_vec3	color;
}	t_cube_plane;

typedef struct s_cube
{
	t_cube_plane	plane[6];
	double			t_root;
	double			len;
	t_vec3			cube_c;
	t_vec3			n_vec;
	t_vec3			n_vec_2;
	t_vec3			color;
}	t_cube;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_vec3	color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3	center;
	double	height;
	double	radius;
	t_vec3	n_vec;
	t_vec3	c_c;
	t_vec3	c_h;
	t_vec3	color;
}	t_cylinder;

typedef struct s_plane
{
	t_vec3		center;
	t_vec3		n_vec;
	t_color3	color;
}	t_plane;

typedef struct s_cone
{
	t_vec3	center;
	t_vec3	c_h;
	double	radius;
	double	height;
	double	cos;
	t_vec3	n_vec;
	t_vec3	color;
}	t_cone;

typedef struct s_para
{
	t_vec3		cen;
	t_plane		pl;
	double		len;
}	t_para;

typedef struct s_obj
{
	enum e_objects	type;
	t_cylinder		cylinder;
	t_sphere		sphere;
	t_cube			cube;
	t_cone			cone;
	t_plane			plane;
	t_para			para;
	struct s_obj	*next;
}	t_obj;

typedef struct s_objlist
{
	t_obj	*first;
	int		list_cnt;
}	t_objlist;

typedef struct s_discrim
{
	t_vec3		ac;
	double		a;
	double		b;
	double		c;
	double		discrim;
	double		root;
}	t_discrim;

typedef struct s_minmax
{
	double	max_x;
	double	min_x;
	double	max_y;
	double	min_y;
}	t_minmax;

typedef struct s_norm
{
	double	root;
	t_vec3	n_vec;
}	t_norm;

// t_obj	object_init(int type, t_point3 point, t_vec3 normal, t_color3 color);
void	add_objlist(t_objlist *list, t_obj *object);
int		range_in_hit(t_discrim *disc, double t_max);
t_norm	hit_sphere(t_sphere sph, t_ray ray, double t_max);
t_norm	hit_cylinder(t_cylinder cyl, t_ray ray, double t_max);
t_norm	hit_cone(t_cone	con, t_ray ray, double t_max);
t_norm	hit_plane(t_plane pln, t_ray ray, double t_max);
t_norm	hit_cube(t_cube cube, t_ray ray, double t_max, t_color3 *color);
t_norm	hit_paraboloid(t_para para, t_ray ray, double t_max);
// double	hit_cube(t_cube cube, t_ray ray, double t_max, t_color3 *color);
double	ft_abs(double num);
void	complete_cube(t_cube *cube);
#endif