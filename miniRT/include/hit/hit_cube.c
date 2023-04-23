/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:00:18 by chanson           #+#    #+#             */
/*   Updated: 2023/04/22 14:10:51 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static t_rot	rotate_plane_z(t_vec3 normal, t_vec3 plane_vertex)
{
	t_vec3x3	rot_z;

	if (normal.x == 1 && normal.y == 0 && normal.z == 0)
	{
		rot_z.v_x = vec3init(1.0, 0.0, 0.0);
		rot_z.v_y = vec3init(0.0, 1.0, 0.0);
		rot_z.v_z = vec3init(0.0, 0.0, 1.0);
		return (rot_z);
	}
	if (normal.x == 0 && normal.y == 0 && normal.z == 0)
		normal = normalize_vec3(plane_vertex);
	rot_z.v_x = vec3init(normal.x / 1.0, normal.y / 1.0, 0);
	rot_z.v_y = vec3init(-normal.y / 1.0, normal.x / 1.0, 0);
	rot_z.v_z = vec3init(0, 0, 1);
	return (rot_z);
}

static t_cube_plane	rot_plane_abcd(t_rot rot, t_cube_plane plane)
{
	t_cube_plane	rot_plane;
	int				i;

	rot_plane.center = vec3x3_x_vec3(rot, plane.center);
	rot_plane.n_vec = vec3x3_x_vec3(rot, plane.n_vec);
	i = -1;
	while (++i < 4)
		rot_plane.plane_vertex[i] = vec3x3_x_vec3(rot, plane.plane_vertex[i]);
	return (rot_plane);
}

static int	in_the_target(t_rot	rot, t_discrim disc, t_cube_plane rot_plane)
{
	t_minmax	m;
	int			i;

	disc.ac = vec3x3_x_vec3(rot, disc.ac);
	rot_plane = rot_plane_abcd(rot, rot_plane);
	m.max_x = -INFINITY;
	m.min_x = INFINITY;
	m.max_y = -INFINITY;
	m.min_y = INFINITY;
	i = -1;
	while (++i < 4)
	{
		if (rot_plane.plane_vertex[i].x < m.min_x)
			m.min_x = rot_plane.plane_vertex[i].x;
		if (rot_plane.plane_vertex[i].x > m.max_x)
			m.max_x = rot_plane.plane_vertex[i].x;
		if (rot_plane.plane_vertex[i].y < m.min_y)
			m.min_y = rot_plane.plane_vertex[i].y;
		if (rot_plane.plane_vertex[i].y > m.max_y)
			m.max_y = rot_plane.plane_vertex[i].y;
	}
	if (disc.ac.x >= m.min_x && disc.ac.x <= m.max_x && \
		disc.ac.y >= m.min_y && disc.ac.y <= m.max_y)
		return (1);
	return (0);
}

static double	hit_plane_c(t_cube_plane rot_plane, t_ray rot_ray, double t_max)
{
	t_discrim	disc;
	t_rot		rot;
	t_vec3		vec_c;

	if (dot_vec3(rot_ray.direction, rot_plane.n_vec) == 0)
		return (0);
	if (dot_vec3(sub_vec3(rot_ray.point, rot_plane.center), \
		rot_plane.n_vec) == 0)
		return (0);
	disc.ac = sub_vec3(rot_ray.point, rot_plane.center);
	disc.a = -1 * dot_vec3(disc.ac, rot_plane.n_vec);
	disc.b = dot_vec3(rot_ray.direction, rot_plane.n_vec);
	disc.root = disc.a / disc.b;
	if (disc.root < 0.0001 || disc.root > t_max)
		return (0);
	disc.ac = add_vec3(rot_ray.point, mul_vec3(rot_ray.direction, disc.root));
	vec_c = normalize_vec3(rot_plane.center);
	rot = rotate_plane_z(vec_c, rot_plane.plane_vertex[0]);
	if (in_the_target(rot, disc, rot_plane) == 0)
		return (0);
	return (disc.root);
}

double	hit_cube(t_obj obj, t_ray ray, double t_max)
{
	t_ray			rot_ray;
	t_cube			cube;
	t_rot			rot;
	t_cube_plane	rot_plane;
	int				i;

	cube = obj.cube;
	i = -1;
	obj.cube.t_root = t_max;
	while (++i < 6)
	{
		rot = rotate_vec_001(cube.plane[i].n_vec);
		rot_ray.point = vec3x3_x_vec3(rot, ray.point);
		rot_ray.direction = vec3x3_x_vec3(rot, ray.direction);
		rot_plane = rot_plane_abcd(rot, cube.plane[i]);
		obj.cube.temp_root = hit_plane_c(rot_plane, rot_ray, obj.cube.t_root);
		if (obj.cube.temp_root > 0 && obj.cube.temp_root < obj.cube.t_root)
			obj.cube.t_root = obj.cube.temp_root;
	}
	if (obj.cube.t_root == INFINITY)
		obj.cube.t_root = 0;
	return (obj.cube.t_root);
}
