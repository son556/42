/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cube_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 22:02:23 by chanson           #+#    #+#             */
/*   Updated: 2023/04/25 18:43:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

static void	_complete_cube_(t_cube *cube, t_vec3 *point)
{
	cube->plane[0].plane_vertex[0] = point[0];
	cube->plane[0].plane_vertex[1] = point[1];
	cube->plane[0].plane_vertex[2] = point[2];
	cube->plane[0].plane_vertex[3] = point[3];
	cube->plane[1].plane_vertex[0] = point[4];
	cube->plane[1].plane_vertex[1] = point[5];
	cube->plane[1].plane_vertex[2] = point[6];
	cube->plane[1].plane_vertex[3] = point[7];
	cube->plane[2].plane_vertex[0] = point[0];
	cube->plane[2].plane_vertex[1] = point[1];
	cube->plane[2].plane_vertex[2] = point[5];
	cube->plane[2].plane_vertex[3] = point[4];
	cube->plane[3].plane_vertex[0] = point[0];
	cube->plane[3].plane_vertex[1] = point[3];
	cube->plane[3].plane_vertex[2] = point[7];
	cube->plane[3].plane_vertex[3] = point[4];
	cube->plane[4].plane_vertex[0] = point[1];
	cube->plane[4].plane_vertex[1] = point[2];
	cube->plane[4].plane_vertex[2] = point[6];
	cube->plane[4].plane_vertex[3] = point[5];
	cube->plane[5].plane_vertex[0] = point[3];
	cube->plane[5].plane_vertex[1] = point[2];
	cube->plane[5].plane_vertex[2] = point[6];
	cube->plane[5].plane_vertex[3] = point[7];
}

static void	complete_cube_(t_cube *cube, t_vec3 *n_vec)
{
	t_vec3	point[8];

	point[0] = add_vec3(cube->plane[0].center, \
		mul_vec3(cube->plane[2].n_vec, cube->len / 2));
	point[0] = add_vec3(point[0], \
		mul_vec3(cube->plane[3].n_vec, cube->len / 2));
	point[1] = add_vec3(point[0], mul_vec3(cube->plane[4].n_vec, cube->len));
	point[2] = add_vec3(point[1], mul_vec3(cube->plane[5].n_vec, cube->len));
	point[3] = add_vec3(point[2], mul_vec3(cube->plane[3].n_vec, cube->len));
	point[4] = add_vec3(point[0], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[5] = add_vec3(point[1], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[6] = add_vec3(point[2], mul_vec3(cube->plane[1].n_vec, cube->len));
	point[7] = add_vec3(point[3], mul_vec3(cube->plane[1].n_vec, cube->len));
	cube->t_root = 0;
	cube->temp_root = 0;
	_complete_cube_(cube, &(point[0]));
}

void	complete_cube(t_cube *cube)
{
	int		i;
	int		j;
	t_vec3	n_vec[6];

	n_vec[0] = cube->n_vec;
	n_vec[1] = normalize_vec3(mul_vec3(n_vec[0], -1));
	n_vec[2] = cube->n_vec_2;
	n_vec[3] = normalize_vec3(cross_vec3(n_vec[0], n_vec[2]));
	n_vec[4] = normalize_vec3(mul_vec3(n_vec[3], -1));
	n_vec[5] = normalize_vec3(mul_vec3(n_vec[2], -1));
	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 6)
		{
			cube->plane[i].n_vec = n_vec[i];
			cube->plane[i].center = add_vec3(cube->cube_c, \
				mul_vec3(n_vec[i], cube->len / 2));
		}
	}
	complete_cube_(cube, n_vec);
}
