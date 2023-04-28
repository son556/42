/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:00:18 by chanson           #+#    #+#             */
/*   Updated: 2023/04/28 15:57:18 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"
#include <stdio.h>

static int	find_theta(t_vec3x3 cabi)
{
	double	cos1;
	double	sin1;
	double	cos2;
	double	sin2;
	double	cosin;

	cos1 = dot_vec3(cabi.v_x, cabi.v_y) / \
		(len_vec3(cabi.v_x) * len_vec3(cabi.v_y));
	cos2 = dot_vec3(cabi.v_x, cabi.v_z) / \
		(len_vec3(cabi.v_x) * len_vec3(cabi.v_z));
	sin1 = sqrt(1 - ft_pow(cos1));
	sin2 = sqrt(1 - ft_pow(cos2));
	cosin = cos1 * cos2 - sin1 * sin2;
	if (cosin <= 1e-5 && cosin >= -1e-5)
	{
		if (cos1 < 0.0 && cos1 >= -1.0)
			return (0);
		if (cos2 >= -1 - 1e-6 && cos2 <= -1 + 1e-6)
			return (0);
		return (1);
	}
	return (0);
}

static int	complete_tri(t_tri *tri, t_cube_plane plane, t_vec3 hit)
{
	int	i;

	i = -1;
	while (++i < 4)
		tri[i].n1 = plane.center;
	tri[0].n2 = plane.plane_vertex[0];
	tri[0].n3 = plane.plane_vertex[1];
	tri[1].n2 = plane.plane_vertex[1];
	tri[1].n3 = plane.plane_vertex[2];
	tri[2].n2 = plane.plane_vertex[2];
	tri[2].n3 = plane.plane_vertex[3];
	tri[3].n2 = plane.plane_vertex[3];
	tri[3].n3 = plane.plane_vertex[0];
	if (hit.x == plane.center.x && \
		hit.y == plane.center.y && hit.z == plane.center.z)
		return (1);
	return (0);
}

static int	where_hit_area(t_cube_plane plane, t_vec3 hit, double len)
{
	t_tri		tri[4];
	int			i;
	t_vec3x3	cabi;

	if (complete_tri(tri, plane, hit) == 1)
		return (1);
	i = -1;
	while (++i < 4)
	{
		cabi.v_x = sub_vec3(hit, plane.center);
		cabi.v_y = sub_vec3(tri[i].n2, tri[i].n1);
		cabi.v_z = sub_vec3(tri[i].n3, tri[i].n1);
		if (find_theta(cabi))
			break ;
	}
	// if (i == 1 || i == 2 || i == 3)
	// 	return (0);
	cabi.v_z = mul_vec3(add_vec3(tri[i].n2, tri[i].n3), 0.5);
	cabi.v_z = sub_vec3(cabi.v_z, plane.center);
	cabi.v_z = normalize_vec3(cabi.v_z);
	cabi.v_x.x = dot_vec3(cabi.v_x, cabi.v_z);
	if (cabi.v_x.x <= len / 2.0 && cabi.v_x.x >= 0)
		return (1);
	// if (cabi.v_x.x <= len / 2)
	// 	return (1);
	return (0);
}

double	hit_cube(t_cube cube, t_ray ray, double t_max, t_color3 *color)
{
	int			i;
	int			j;
	t_vec3		hit;
	t_discrim	disc;

	i = -1;
	cube.t_root = t_max;
	while (++i < 6)
	{
		disc.ac = sub_vec3(ray.point, cube.plane[i].center);
		disc.a = -1 * dot_vec3(disc.ac, cube.plane[i].n_vec);
		disc.b = dot_vec3(cube.plane[i].n_vec, ray.direction);
		if (disc.b > -1e-5 && disc.b < 1e-5)
			continue ;
		disc.c = disc.a / disc.b;
		if (disc.c <= 1e-5 || disc.c >= cube.t_root)
			continue ;
		hit = ray_at(ray, disc.c);
		if (where_hit_area(cube.plane[i], hit, cube.len) == 1)
		{
			color->x = cube.plane[i].color.x;
			color->y = cube.plane[i].color.y;
			color->z = cube.plane[i].color.z;
			cube.t_root = disc.c;
		}
	}
	if (cube.t_root == t_max)
		return (0);
	return (cube.t_root);
}
