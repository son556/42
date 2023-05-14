/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:37:11 by chanson           #+#    #+#             */
/*   Updated: 2023/05/14 14:39:14 by chanson          ###   ########.fr       */
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
	PARABOLOID,
	METAL,
	GLASS,
	PLASTIC,
	HOLLOWGLASS
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
}	t_cube;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_vec3	center;
	double	height;
	double	radius;
	t_vec3	n_vec;
	t_vec3	c_c;
	t_vec3	c_h;
}	t_cylinder;

typedef struct s_plane
{
	t_vec3		center;
	t_vec3		n_vec;
	t_color3	color;
}	t_plane;

typedef struct s_cone
{
	t_vec3	c_h;
	double	radius;
	double	height;
	double	c_cos;
	t_vec3	n_vec;
	t_plane	pl;
}	t_cone;

typedef struct s_para
{
	t_vec3		cen;
	t_plane		pl;
	double		len;
	double		r;
	double		len_cc;
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
	t_color3		color;
	enum e_objects	material;
	double			fuzz;
	double			ref_idx;
}	t_obj;

typedef struct s_discrim
{
	t_vec3		ac;
	double		a;
	double		b;
	double		c;
	double		discrim;
	double		root;
}	t_discrim;

typedef struct s_norm
{
	double			root;
	t_vec3			n_vec;
	t_point3		hit;
	double			t_max;
	t_color3		albedo;
	t_light			light;
	t_light			ambi;
	t_light			spec;
	t_color3		color;
	int				front;
	int				depth;
	int				p_depth;
	int				hit_idx;
	enum e_objects	material;
}	t_norm;

int			range_in_hit(t_discrim *disc, double t_max);
t_norm		hit_sphere(t_sphere sph, t_ray ray, double t_max);
t_norm		hit_cylinder_2(t_cylinder cyl, t_ray ray, double t_max);
t_norm		hit_cylinder(t_cylinder cyl, t_ray ray, double t_max);
t_norm		hit_cone(t_cone	con, t_ray ray, double t_max);
t_norm		hit_plane(t_plane pln, t_ray ray, double t_max);
t_norm		hit_cube(t_cube cube, t_ray ray, double t_max, t_color3 *color);
t_norm		hit_paraboloid(t_para para, t_ray ray, double t_max);
double		paraboloid_r(t_para	para);
void		complete_cone(t_cone *con, t_vec3 cen, t_vec3 n_vec, t_vec3 rh);
void		complete_cube(t_cube *cube, t_vec3x3 n1_n2_c, double l);
void		complete_para(t_para *para, t_vec3 center, t_vec3 move, double len);
void		complete_sphere(t_sphere *sp, t_vec3 cen, double r);
void		complete_cyl(t_cylinder *cyl, t_vec3x3 cen_vec_rh);
void		complete_plane(t_plane *pl, t_vec3 cen, t_vec3 vec);
t_vec3x3	cen_vec_rh_init(t_vec3 cen, t_vec3 vec, t_vec3 rh);
t_vec3x3	make_n1_n2_c(t_vec3 n1, t_vec3 n2, t_vec3 cen);
t_color3	ray_color(t_ray ray, t_obj *obj, t_norm *norm, int n);
t_color3	test_color(t_ray ray, t_obj *obj, t_norm *norm, int n);
t_norm		find_hit_function(t_ray ray, t_obj obj, double t_max);
t_ray		diffuse_ray(t_norm norm, t_ray ray);
t_ray		specular_ray(t_norm norm, t_ray ray, double fuzz);
t_ray		refract_ray(t_norm norm, t_ray ray, double ref_idx);
int			shade(t_norm norm, t_obj *obj, int n, int m);
int			front_or_back(t_ray ray, t_norm norm);
void		display_cone(t_cone con);
#endif