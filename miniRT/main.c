/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/05/27 17:03:31 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/vec3.h"
#include "./include/ray.h"
#include "./include/hit.h"
#include "./include/mlx_function.h"
#include <stdio.h>

int	argb_(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_vars		mlx;
	t_ray		ray;
	double		res_ratio = 16.0 / 9.0;
	double		point_x;
	double		point_y;

	point_y = 400;
	point_x = point_y * res_ratio;
	double	theta = getradian(60);
	double	h = tan(theta / 2);
	double	vp_height = 2.0 * h;
	double	vp_width = res_ratio * vp_height;
	// double	vp_length = 1.0;
	t_vec3	look_from = vec3init(0, 0, 0);
	t_vec3	look_at = vec3init(0, 0, -1);
	t_vec3	vup = vec3init(0, 1, 0);

	t_vec3	w_vec = normalize_vec3(sub_vec3(look_from, look_at));
	t_vec3	u_vec = normalize_vec3(cross_vec3(vup, w_vec));
	t_vec3	v_vec = cross_vec3(w_vec, u_vec);
	
	t_vec3	horizontal = mul_vec3(u_vec, vp_width);
	t_vec3	vertical = mul_vec3(v_vec, vp_height);
	t_vec3	origin = look_from;
	t_vec3	ll_corner = sub_vec3(origin, mul_vec3(horizontal, 0.5));
	ll_corner = sub_vec3(ll_corner, mul_vec3(vertical, 0.5));
	ll_corner = sub_vec3(ll_corner, w_vec);

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

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, point_x, point_y, "test");


	t_obj	obj_arr[5];
	obj_arr[0] = obj_cylinder;
	obj_arr[1] = obj_cone;
	obj_arr[2] = obj_sphere;
	obj_arr[3] = obj_cube;
	obj_arr[4] = obj_paraboloid;

	t_norm	norm;

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

	t_obj	obj_light2;
	obj_light2.type = SPHERE;
	complete_sphere(&obj_light2.sphere, vec3init(0, 2, -10), 1);
	obj_light2.material = LIGHT;

	t_obj	obj_perlin[5];

	obj_perlin[0] = obj_perlin_pl;
	obj_perlin[1] = obj_perlin_sph;
	obj_perlin[2] = obj_light;
	obj_perlin[3] = obj_sph;
	obj_perlin[4] = obj_sph2;

	norm.background = vec3init(0, 0, 0);
	norm.light.color = vec3init(7, 7, 7);
	for (int j = point_y - 1 ; j >= 0; --j)
	{
		for (int i = 0 ; i < point_x ; i++)
		{
			t_vec3 argb = vec3init(0, 0, 0);
			for (int k = 0; k < 2000; k++)
			{
				double u = (i + random_0_to_1()) / (point_x - 1);
				double v = (j + random_0_to_1()) / (point_y - 1);
				ray.point = origin;
				ray.direction = vec3init(ll_corner.x + u*horizontal.x + v*vertical.x - origin.x,
								ll_corner.y + u*horizontal.y + v*vertical.y - origin.y,
								ll_corner.z + u*horizontal.z + v*vertical.z - origin.z);
				ray.direction = normalize_vec3(ray.direction);
				norm.depth = 50;
				norm.hit_idx = -1;
				t_vec3 argb2 = light_color(ray, obj_perlin, &norm, 4);
				argb = add_vec3(argb, argb2);
			}
			argb = div_vec3(argb, 2000);
			argb.x = sqrt(argb.x);
			argb.y = sqrt(argb.y);
			argb.z = sqrt(argb.z);
			argb = minmax_vec3(argb, 0, 1);
			int	color = argb_(0, (int)(argb.x * 255.999), (int)(argb.y * 255.999), (int)(argb.z * 255.999));
			mlx_pixel_put(mlx.mlx, mlx.win, i, point_y - 1 - j, color);
		}
	}
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
