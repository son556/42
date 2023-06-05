/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_mem.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:40:41 by chanson           #+#    #+#             */
/*   Updated: 2023/06/02 14:31:22 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/vec3.h"
#include "./include/ray.h"
#include "./include/hit.h"
#include "./include/mlx_function.h"
#include <stdio.h>

int	main(void)
{
	t_list	list;
	t_norm	norm;

	set_main(&(list.m));
	list.first = NULL;

	t_obj	obj_sph;
	obj_sph.type = SPHERE;
	complete_sphere(&obj_sph.sphere, vec3init(2, -3, -10), 1.0);
	obj_sph.material = GLASS;
	obj_sph.color = vec3init(1.0, 1.0, 1.0);
	obj_sph.ref_idx = 2.0;

	t_obj	obj_sph2;
	obj_sph2.type = SPHERE;
	complete_sphere(&obj_sph2.sphere, vec3init(2, -3, -10), -0.9);
	obj_sph2.material = GLASS;
	obj_sph2.color = vec3init(1.0, 1.0, 1.0);
	obj_sph2.ref_idx = 2.0;

	// sort_obj_by_axis(obj_test, 0, 4, rand() % 3);
	// norm.tree.head = NULL;
	// make_bvh_tree(obj_test, 0, 4, &norm);
	// norm.light = light_init(vec3init(0, 10, -10), vec3init(1, 1, 1), 0.8);

	perm_and_ranfloat(norm.noise.p_x, norm.noise.p_y, norm.noise.p_z, norm.noise.ranfloat);

	t_obj	obj_perlin_pl;
	obj_perlin_pl.type = XYZ_PLANE;
	complete_xyz_pl(&obj_perlin_pl.xyz_pl, vec3init(0, -4, -10), 5, 1);
	obj_perlin_pl.color = vec3init(0, 0.8, 0);
	obj_perlin_pl.material = PLASTIC;
	// obj_perlin_pl.texture = IMAGE_TEXTURE;

	t_obj	obj_perlin_sph;
	obj_perlin_sph.type = SPHERE;
	complete_sphere(&obj_perlin_sph.sphere, vec3init(0, -3, -10), 1.0);
	obj_perlin_sph.material = PLASTIC;
	obj_perlin_sph.color = vec3init(0, 0, 1);
	obj_perlin_sph.texture = IMAGE_TEXTURE;

	t_obj	obj_light;
	obj_light.type = XYZ_PLANE;
	complete_xyz_pl(&obj_light.xyz_pl, vec3init(0, 2, -10), 1, 1);
	obj_light.material = LIGHT;

	t_obj	obj_pl_sph3;
	obj_pl_sph3.type = SPHERE;
	complete_sphere(&obj_pl_sph3.sphere, vec3init(-2, -3, -10), 1.0);
	obj_pl_sph3.material = METAL;
	obj_pl_sph3.color = vec3init(0.8, 0.6, 0);
	obj_pl_sph3.fuzz = 0;

	t_obj	obj_pl_cone;
	obj_pl_cone.type = CONE;
	complete_cone(&obj_pl_cone.cone, vec3init(-2, -4, -10), \
		vec3init(0, 1, 0), vec3init(1, 2, 0));
	obj_pl_cone.material = METAL;
	obj_pl_cone.color = vec3init(0.8, 0.6, 0);
	obj_pl_cone.fuzz = 0.2;

	t_obj	obj_perlin[6];

	obj_perlin[0] = obj_perlin_pl;
	obj_perlin[1] = obj_perlin_sph;
	obj_perlin[2] = obj_light;
	obj_perlin[3] = obj_sph;
	obj_perlin[4] = obj_pl_sph3;
	obj_perlin[5] = obj_sph2;

	norm.background = vec3init(0, 0, 0);
	norm.light.color = vec3init(7, 7, 7);
	list.m.arr_cnt = 6;
	list.first = NULL;
	obj_perlin->mlx.mlx = &(list.m.mlx);
	texture_img(&(obj_perlin->mlx));
	set_task_list(&list, 6, obj_perlin);
	thread_start(&list, norm);
	mlx_key_hook(list.m.mlx.win, key_hook, &(list.m.mlx));
	mlx_hook(list.m.mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(list.m.mlx.mlx);
	return (0);
}

