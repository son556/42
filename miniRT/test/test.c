/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:06:26 by chanson           #+#    #+#             */
/*   Updated: 2023/04/29 16:48:08 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"
#include "../include/hit.h"
#include <stdio.h>

void	display_cube(t_cube cube)
{
	for (int i = 0; i < 6; i++)
	{
		printf("plane[%d]\n", i);
		for (int j = 0; j < 4; j++)
		{
			display_vec3(cube.plane[i].plane_vertex[j]);
		}
		printf("\n");
	}
}

void	display_cube_n_vec(t_cube cube)
{
	for (int i = 0; i < 6; i++)
	{
		printf("plane[%d] n_vec: ", i);
		display_vec3(cube.plane[i].n_vec);
	}
}

static t_rot	rotate_plane_z(t_cube_plane	plane)
{
	t_vec3	point;
	t_vec3	l_vec;
	t_vec3	rot;
	t_rot	rot_r;

	l_vec = sub_vec3(plane.plane_vertex[0], plane.plane_vertex[3]);
	point = plane.plane_vertex[0];
	rot.x = (ft_pow(l_vec.y) * point.x - l_vec.x * l_vec.y * point.y) / \
		(ft_pow(l_vec.x) + ft_pow(l_vec.y));
	rot.y = (-l_vec.y / l_vec.x) * rot.x;
	rot.z = rot.y / rot.x;
	point.z = sqrt(ft_pow(rot.y) + ft_pow(rot.x));
	rot_r.v_x = vec3init(rot.x / point.z, rot.y / point.z, 0);
	rot_r.v_y = vec3init(-rot.y / point.z, rot.x / point.z, 0);
	rot_r.v_z = vec3init(0, 0, 1);
	return (rot_r);
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

	vec_c.x = dot_vec3(rot_ray.direction, rot_plane.n_vec);
	if (vec_c.x <= 1e-5 && vec_c.x >= -1e-5)
		return (0);
	vec_c.x = dot_vec3(sub_vec3(rot_ray.point, rot_plane.center), \
		rot_plane.n_vec);
	if (vec_c.x <= 1e-5 && vec_c.x >= -1e-5)
		return (0);
	disc.ac = sub_vec3(rot_ray.point, rot_plane.center);
	disc.a = -1 * dot_vec3(disc.ac, rot_plane.n_vec);
	disc.b = dot_vec3(rot_ray.direction, rot_plane.n_vec);
	disc.root = disc.a / disc.b;
	if (disc.root < 0.0001 || disc.root > t_max)
		return (0);
	disc.ac = ray_at(rot_ray, disc.root);
	vec_c = normalize_vec3(rot_plane.center);
	rot = rotate_plane_z(rot_plane);
	if (in_the_target(rot, disc, rot_plane) == 0)
		return (0);
	return (disc.root);
}

void	display_plane(t_cube_plane plane)
{
	printf("point 1: ");
	display_vec3(plane.plane_vertex[0]);
	printf("point 2: ");
	display_vec3(plane.plane_vertex[1]);
	printf("point 3: ");
	display_vec3(plane.plane_vertex[2]);
	printf("point 4: ");
	display_vec3(plane.plane_vertex[3]);
}

int	main(void)
{
	t_rot	rot;
	t_obj	obj_cube;
	t_cube	cube;
	t_cube_plane	rot_pl;
	t_rot	rot2;

	obj_cube.type = CUBE;
	obj_cube.cube.n_vec = vec3init(0, 0, 1);
	obj_cube.cube.n_vec_2 = normalize_vec3(vec3init(1, 0, 0));
	obj_cube.cube.len = 2.0;
	obj_cube.cube.cube_c = vec3init(0, 0, 0);
	obj_cube.cube.plane[0].color = vec3init(1, 0, 0);
	obj_cube.cube.plane[1].color = vec3init(0, 0, 0);
	obj_cube.cube.plane[2].color = vec3init(0, 1, 0);
	obj_cube.cube.plane[3].color = vec3init(0, 0, 1);
	obj_cube.cube.plane[4].color = vec3init(1, 1, 0);
	obj_cube.cube.plane[5].color = vec3init(0, 1, 1);
	complete_cube(&(obj_cube.cube));
	display_cube(obj_cube.cube);
	printf("\n\n");
	display_cube_n_vec(obj_cube.cube);
	return (0);
}


// cc test.c ./include/vec_utils/vec_utils.c ./include/vec_utils2.c ./include/vec_utils3.c