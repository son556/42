/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/05/11 20:47:16 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/vec3.h"
#include "./include/ray.h"
#include "./include/hit.h"
#include "./include/mlx_function.h"
#include <stdio.h>

void	display_cube(t_cube cube)
{
	for (int i = 0; i < 6; i++)
	{
		printf("center: %f %f %f\n", cube.plane[i].center.x, cube.plane[i].center.y, \
			cube.plane[i].center.z);
		printf("n_vec: ");
		printf("%f %f %f\n\n", cube.plane[i].n_vec.x, cube.plane[i].n_vec.y, cube.plane[i].n_vec.z);
		for (int j = 0; j < 4; j++)
		{
			printf("%d: %f %f %f\n", i, cube.plane[i].plane_vertex[j].x, cube.plane[i].plane_vertex[j].y, \
			cube.plane[i].plane_vertex[j].z);
		}
		printf("\n");
	}
}

void	display_cube_plane(t_cube_plane plane)
{
	for (int i = 0; i < 4; i++)
	{
		printf("vertex[%d]: ", i);
		display_vec3(plane.plane_vertex[i]);
	}
}

void	display_norm(t_norm norm)
{
	printf("root: %f t_max %f\n\n", norm.root, norm.t_max);
}

int	argb_(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	main(void)
{
	t_vars		mlx;
	t_ray		ray;
	double		res_ratio = 1.0 / 1.0;
	double		point_x;
	double		point_y;

	point_x = 700;
	point_y = 700;
	double	vp_height = 2.0;
	double	vp_width = res_ratio * vp_height;
	double	vp_length = 1.0;
	t_vec3	horizontal = vec3init(vp_width, 0, 0);
	t_vec3	vertical = vec3init(0, vp_height, 0);
	t_vec3	ll_corner = vec3init( (- horizontal.x / 2) + (-vertical.x / 2) + (0)
		 					, (- horizontal.y / 2) + (-vertical.y / 2) + (0)
						 , (- horizontal.z / 2) + (-vertical.z / 2) + (-vp_length));
	
	t_obj		obj_cylinder;
	obj_cylinder.type = CYLINDER;
	complete_cyl(&obj_cylinder.cylinder, cen_vec_rh_init(vec3init(0, -5, -10), \
		vec3init(0, 1, 0), vec3init(8.0, 2.0, 0)));
	obj_cylinder.color = vec3init(0, 1, 0);

	t_obj		obj_cone;
	obj_cone.type = CONE;
	complete_cone(&obj_cone.cone, vec3init(0.3, 0, -10), \
		vec3init(1, 0, 0), vec3init(1, 2, 0));
	obj_cone.color = vec3init(1, 1, 0);

	t_obj	obj_sphere;
	obj_sphere.type = SPHERE;
	complete_sphere(&obj_sphere.sphere, vec3init(0, -3, -10), 1.0);
	obj_sphere.color = vec3init(0, 0, 1);

	t_obj	obj_plane;
	obj_plane.type = PLANE;
	complete_plane(&obj_plane.plane, vec3init(0, 0, -10), \
		normalize_vec3(vec3init(0, 1, 0)));
	obj_plane.color = vec3init(0, 1, 1);

	t_obj	obj_cube;
	obj_cube.type = CUBE;
	complete_cube(&obj_cube.cube, make_n1_n2_c(vec3init(1, 1, 1), \
		vec3init(1, 0, -1), vec3init(0, 3, -10)), 2.0);
	obj_cube.color = vec3init(1, 0, 1);

	t_obj	obj_paraboloid;
	obj_paraboloid.type = PARABOLOID;
	complete_para(&obj_paraboloid.para, vec3init(0, -6, -10), vec3init(0, -1, 0), 6.0);
	obj_paraboloid.color = vec3init(1, 0, 0);

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, point_x, point_y, "test");


	t_obj	obj_arr[5];
	obj_arr[0] = obj_cylinder;
	obj_arr[1] = obj_cone;
	obj_arr[2] = obj_sphere;
	obj_arr[3] = obj_cube;
	obj_arr[4] = obj_paraboloid;

	t_norm	norm;

	t_obj		obj_cyl;
	obj_cyl.type = CYLINDER;
	complete_cyl(&obj_cyl.cylinder, cen_vec_rh_init(vec3init(0, -2, -10), \
		vec3init(0, 1, 0), vec3init(1, 2, 0)));
	obj_cyl.color = vec3init(0, 1, 1);

	t_obj	obj_para;
	obj_para.type = PARABOLOID;
	complete_para(&obj_para.para, vec3init(0, -5, -10), vec3init(0, 1, 0), 3.0);
	obj_para.color = vec3init(0, 1, 0);

	t_obj	obj_test[2];
	obj_test[0] = obj_arr[0];
	obj_test[1] = obj_arr[2];
	norm.light = light_init(vec3init(0, 10, -10), vec3init(1, 1, 1), 0.8);
	for (int j = point_y - 1 ; j >= 0; --j)
	{
		for (int i = 0 ; i < point_x ; i++)
		{
			t_vec3 argb = vec3init(0, 0, 0);
			for (int k = 0; k < 9; k++)
			{
				double u = (i + random_0_to_1()) / (point_x - 1);
				double v = (j + random_0_to_1()) / (point_y - 1);
				ray.point = vec3init(0, 0, 0);
				ray.direction = vec3init(ll_corner.x + u*horizontal.x + v*vertical.x,
								ll_corner.y + u*horizontal.y + v*vertical.y,
								ll_corner.z + u*horizontal.z + v*vertical.z);
				ray.direction = normalize_vec3(ray.direction);
				norm.depth = 50;
				norm.hit_idx = -1;
				norm.p_depth = norm.depth;
				t_vec3 argb2 = test_color(ray, obj_test, &norm, 2);
				argb = add_vec3(argb, argb2);
			}
			argb = div_vec3(argb, 9.0);
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
