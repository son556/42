/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/05/29 21:05:01 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/vec3.h"
#include "./include/ray.h"
#include "./include/hit.h"
#include "./include/mlx_function.h"
#include "./include/pthread.h"
#include <stdio.h>

int	argb_(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

static void	set_ray(t_main m, t_ray *ray, t_for_idx p)
{
	ray->point = m.origin;
	ray->direction.x = m.ll_corner.x + p.u * m.horizontal.x + \
		p.v * m.vertical.x - m.origin.x;
	ray->direction.y = m.ll_corner.y + p.u * m.horizontal.y + \
		p.v * m.vertical.y - m.origin.y;
	ray->direction.z = m.ll_corner.z + p.u * m.horizontal.z + \
		p.v * m.vertical.z - m.origin.z;
	ray->direction = normalize_vec3(ray->direction);
}

void	*draw(void *arg)
{
	t_thread	*thr;
	t_for_idx	p;
	t_task		task;
	t_ray		ray;
	t_list		*list;

	thr = (t_thread *)arg;
	list = thr->list;
	while (1)
	{
		task = out_task(thr->list);
		if (task.start == -1)
			break ;
		// printf("idx: %d, start: %d, end: %d\n", thr->thread_idx, task.start, task.end);
		p.j = task.end + 1;
		while (--(p.j) >= task.start)
		{
			p.i = -1;
			while (++(p.i) < list->point_x)
			{
				p.argb = vec3init(0, 0, 0);
				p.k = -1;
				while (++(p.k) < 100)
				{
					// printf("mid mid k: %d idx: %d i: %d p_x: %d\n", p.k, thr->thread_idx, p.i, list->point_x);
					p.u = (p.i + random_0_to_1()) / (thr->list->point_x - 1);
					p.v = (p.j + random_0_to_1()) / (thr->list->m.point_y - 1);
					ray.point = thr->list->m.origin;
					set_ray(list->m, &ray, p);
					// printf("mid sos: %d idx: %d i: %d p_x: %d\n", p.k, thr->thread_idx, p.i, list->point_x);
					thr->norm.depth = 15;
					thr->norm.hit_idx = -1;
					// printf("th_idx: %d, j: %d, i: %d, k: %d, addr: %p\n", thr->thread_idx, p.j, p.i, p.k, &(thr->norm));
					p.argb2 = light_color(ray, thr->list->obj_list, &(thr->norm), thr->list->m.arr_cnt);
					p.argb = add_vec3(p.argb, p.argb2);
				}
				p.argb = div_vec3(p.argb, 100);
				p.argb.x = sqrt(p.argb.x);
				p.argb.y = sqrt(p.argb.y);
				p.argb.z = sqrt(p.argb.z);
				p.argb = minmax_vec3(p.argb, 0, 1);
				p.color = argb_(0, (int)(p.argb.x * 255.999), (int)(p.argb.y * 255.999), (int)(p.argb.z * 255.999));
				pthread_mutex_lock(&(thr->list->key_draw));
				mlx_pixel_put(list->m.mlx.mlx, list->m.mlx.win, p.i, 700 - 1 - p.j, p.color);
				pthread_mutex_unlock(&(thr->list->key_draw));
			}
		}
	}
	return (0);
}

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

	t_obj		obj_cylinder;
	obj_cylinder.type = CYLINDER;
	complete_cyl(&obj_cylinder.cylinder, cen_vec_rh_init(vec3init(0, -5, -10), \
		vec3init(0, 1, 0), vec3init(8.0, 2.0, 0)));
	obj_cylinder.color = vec3init(0, 1, 0);
	obj_cylinder.material = PLASTIC;
	obj_cylinder.texture = CHECK_TEXTURE;

	t_obj		obj_cone;
	obj_cone.type = CONE;
	complete_cone(&obj_cone.cone, vec3init(0, -2, -10), \
		vec3init(0, 1, 0), vec3init(2, 3, 0));
	obj_cone.color = vec3init(1, 0, 0);
	obj_cone.material = PLASTIC;

	t_obj	obj_sphere;
	obj_sphere.type = SPHERE;
	complete_sphere(&obj_sphere.sphere, vec3init(0, -3, -10), 1.0);
	obj_sphere.color = vec3init(0.8, 0.6, 0.2);
	obj_sphere.material = METAL;
	obj_sphere.fuzz = 0.0;
	obj_sphere.ref_idx = 1.5;

	t_obj	obj_plane;
	obj_plane.type = PLANE;
	complete_plane(&obj_plane.plane, vec3init(0, 0, -10), \
		normalize_vec3(vec3init(0, 1, 0)));
	obj_plane.color = vec3init(0, 1, 1);

	t_obj	obj_cube;
	obj_cube.type = CUBE;
	obj_cube.material = METAL;
	complete_cube(&obj_cube.cube, make_n1_n2_c(vec3init(1, 1, 1), \
		vec3init(1, 0, -1), vec3init(0, 5, -10)), 2.0);
	obj_cube.color = vec3init(0.6, 0.8, 0.2);
	obj_cube.fuzz = 0;
	obj_cube.ref_idx = 1.5;

	t_obj	obj_paraboloid;
	obj_paraboloid.type = PARABOLOID;
	complete_para(&obj_paraboloid.para, vec3init(0, -2, -10), vec3init(0, 1, 0), 3.0);
	obj_paraboloid.color = vec3init(1, 0, 0.5);
	obj_paraboloid.material = METAL;
	obj_paraboloid.fuzz = 0;

	t_obj	obj_arr[5];
	obj_arr[0] = obj_cylinder;
	obj_arr[1] = obj_cone;
	obj_arr[2] = obj_sphere;
	obj_arr[3] = obj_cube;
	obj_arr[4] = obj_paraboloid;

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

	t_obj	obj_sph3;
	obj_sph3.type = SPHERE;
	complete_sphere(&obj_sph3.sphere, vec3init(2, -3, -10), 1.0);
	obj_sph3.material = METAL;
	obj_sph3.color = vec3init(0.8, 0.6, 0.2);
	obj_sph3.fuzz = 0;

	t_obj	obj_sph4;
	obj_sph4.type = SPHERE;
	complete_sphere(&obj_sph4.sphere, vec3init(-2, -3, -10), 1.0);
	obj_sph4.material = PLASTIC;
	obj_sph4.fuzz = 0;
	obj_sph4.color = vec3init(0, 0.2, 1);
	obj_sph4.texture = NOISE_TEXTURE;

	t_obj	obj_test[5];

	obj_test[0] = obj_arr[0];
	obj_test[1] = obj_sph;
	obj_test[2] = obj_sph2;
	obj_test[3] = obj_sph3;
	obj_test[4] = obj_sph4;
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

	t_obj	obj_perlin_sph;
	obj_perlin_sph.type = SPHERE;
	complete_sphere(&obj_perlin_sph.sphere, vec3init(0, -3, -10), 1.0);
	obj_perlin_sph.material = PLASTIC;
	obj_perlin_sph.color = vec3init(0, 0.2, 1);
	obj_perlin_sph.texture = NOISE_TEXTURE;

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

	t_obj	obj_perlin[6];

	obj_perlin[0] = obj_perlin_pl;
	obj_perlin[1] = obj_perlin_sph;
	obj_perlin[2] = obj_light;
	obj_perlin[3] = obj_sph;
	obj_perlin[4] = obj_sph2;
	obj_perlin[5] = obj_pl_sph3;

	norm.background = vec3init(0, 0, 0);
	norm.light.color = vec3init(7, 7, 7);
	list.m.arr_cnt = 6;
	list.first = NULL;
	set_task_list(&list, 6, obj_perlin);
	thread_start(&list, norm);
	mlx_key_hook(list.m.mlx.win, key_hook, &(list.m.mlx));
	mlx_hook(list.m.mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(list.m.mlx.mlx);
	return (0);
}
