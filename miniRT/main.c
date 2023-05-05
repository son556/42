/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/05/05 17:40:03 by chanson          ###   ########.fr       */
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
	complete_cyl(&obj_cylinder.cylinder, cen_vec_col_init(vec3init(0, -2, -10), \
		vec3init(0, 1, 0), vec3init(1, 0, 1)), 1.0, 2.0);

	t_obj		obj_cone;
	obj_cone.type = CONE;
	complete_cone(&obj_cone.cone, vec3init(0, -2, -10), \
		vec3init(0, 1, 0), vec3init(2, 5, 0));
	
	t_obj	obj_sphere;
	obj_sphere.type = SPHERE;
	complete_sphere(&obj_sphere.sphere, vec3init(0, -2, -10), vec3init(0, 0, 1), 1.5);

	t_obj	obj_plane;
	obj_plane.type = PLANE;
	complete_plane(&obj_plane.plane, vec3init(0, 0, -10), \
		normalize_vec3(vec3init(0, 1, 0)), vec3init(1, 0, 0));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, point_x, point_y, "test");

	t_obj	obj_cube;
	obj_cube.type = CUBE;
	complete_cube(&obj_cube.cube, make_n1_n2_c(vec3init(1, 1, 1), \
		vec3init(1, 0, -1), vec3init(0, -2, -10)), vec3init(1, 0, 0), 2.0);

	t_obj	obj_paraboloid;

	obj_paraboloid.type = PARABOLOID;
	complete_para(&obj_paraboloid.para, vec3init(0, -3, -10), vec3init(0, 1, 0), 3.0);

	t_obj	obj_arr[6];
	obj_arr[0] = obj_cylinder;
	obj_arr[1] = obj_cone;
	obj_arr[2] = obj_sphere;
	obj_arr[3] = obj_plane;
	obj_arr[4] = obj_cube;
	obj_arr[5] = obj_paraboloid;
	for (int j = point_y - 1 ; j >= 0; --j)
	{
		for (int i = 0 ; i < point_x ; i++)
		{
			double u = i / (point_x - 1);
			double v = j / (point_y - 1);
			ray.point = vec3init(0, 0, 0);
			ray.direction = vec3init(ll_corner.x + u*horizontal.x + v*vertical.x,
							ll_corner.y + u*horizontal.y + v*vertical.y,
							ll_corner.z + u*horizontal.z + v*vertical.z);
			ray.direction = normalize_vec3(ray.direction);

			t_vec3 argb = ray_color(ray, obj_arr, 6);

			int	color = argb_(0, argb.x * 255.999, argb.y * 255.999, argb.z * 255.999);
			mlx_pixel_put(mlx.mlx, mlx.win, i, point_y - 1 - j, color);
		}
	}
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
