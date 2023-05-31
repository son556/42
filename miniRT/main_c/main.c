/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/05/31 16:44:30 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./main.h"

void	thread_start(t_list	*list, t_norm norm)
{
	t_thread	thread_list[6];
	int			i;

	i = -1;
	set_thread_lst(thread_list, list, norm);
	while (++i < 6)
		pthread_create(&(thread_list[i].thread), NULL, \
			&draw, (void *)&(thread_list[i]));
	i = -1;
	while (++i < 6)
		pthread_join(thread_list[i].thread, NULL);
	pthread_mutex_destroy(&(list->key));
	pthread_mutex_destroy(&(list->key_draw));
}

void	texture_img(t_mlx *mlx)
{
	mlx->block_c.data.img = mlx_xpm_file_to_image(mlx->mlx, \
		"./xpm/blockcolor.xpm", &mlx->block_c.width, &mlx->block_c.height);
	mlx->block_c.data.addr = mlx_get_data_addr(mlx->block_c.data.img, \
		&mlx->block_c.data.bits_per_pixel, &mlx->block_c.data.line_length \
		, &mlx->block_c.data.endian);
	mlx->block_b.data.img = mlx_xpm_file_to_image(mlx->mlx, \
		"./xpm/blocknormal.xpm", &mlx->block_b.width, &mlx->block_b.height);
	mlx->block_b.data.addr = mlx_get_data_addr(mlx->block_b.data.img, \
		&mlx->block_b.data.bits_per_pixel, &mlx->block_b.data.line_length \
		, &mlx->block_b.data.endian);
}

void	set_main(t_main *m)
{
	m->res_ratio = 16.0 / 9.0;
	m->point_y = 700;
	m->point_x = m->point_y * m->res_ratio;
	m->theta = getradian(60);
	m->h = tan(m->theta / 2);
	m->vp_height = 2.0 * m->h;
	m->vp_width = m->res_ratio * m->vp_height;
	m->look_from = vec3init(0, 0, 0);
	m->look_at = vec3init(0, 0, -1);
	m->vup = vec3init(0, 1, 0);
	m->w_vec = normalize_vec3(sub_vec3(m->look_from, m->look_at));
	m->u_vec = normalize_vec3(cross_vec3(m->vup, m->w_vec));
	m->v_vec = cross_vec3(m->w_vec, m->u_vec);
	m->horizontal = mul_vec3(m->u_vec, m->vp_width);
	m->vertical = mul_vec3(m->v_vec, m->vp_height);
	m->origin = m->look_from;
	m->ll_corner = sub_vec3(m->origin, mul_vec3(m->horizontal, 0.5));
	m->ll_corner = sub_vec3(m->ll_corner, mul_vec3(m->vertical, 0.5));
	m->ll_corner = sub_vec3(m->ll_corner, m->w_vec);
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, m->point_x, m->point_y, "test");
}

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
	obj_sph.ref_idx = 1.5;

	t_obj	obj_sph2;
	obj_sph2.type = SPHERE;
	complete_sphere(&obj_sph2.sphere, vec3init(2, -3, -10), -0.9);
	obj_sph2.material = GLASS;
	obj_sph2.color = vec3init(1.0, 1.0, 1.0);
	obj_sph2.ref_idx = 1.5;

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
	obj_pl_sph3.material = PLASTIC;
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
