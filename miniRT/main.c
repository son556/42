/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 22:11:28 by chanson           #+#    #+#             */
/*   Updated: 2023/04/25 19:36:25 by chanson          ###   ########.fr       */
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
		printf("n_vec\n");
		printf("%f %f %f\n\n", cube.plane[i].n_vec.x, cube.plane[i].n_vec.y, cube.plane[i].n_vec.z);
		for (int j = 0; j < 4; j++)
		{
			printf("%f %f %f\n", cube.plane[i].plane_vertex[j].x, cube.plane[i].plane_vertex[j].y, \
			cube.plane[i].plane_vertex[j].z);
		}
		printf("\n");
	}
}

t_vec3	ray_color(t_ray ray, t_obj obj)
{
	t_vec3	color;
	double	t_max;
	double	t;

	t_max = INFINITY;
	// t = hit_cylinder(obj.cylinder, ray, t_max);
	// t = hit_cone(obj.cone, ray, t_max);
	// t = hit_sphere(obj.sphere, ray, t_max);
	// t = hit_plane(obj.plane, ray, t_max);
	t = hit_cube(obj, ray, t_max, &color);
	if (t > 0.0)
	{
		t_vec3	tmp = ray_at(ray, t);
		t_vec3	N = normalize_vec3(vec3init(tmp.x, tmp.y, tmp.z - (-1)));
		// color = mul_vec3(vec3init(N.x + 1, N.y + 1, N.z + 1), 0.5);
		return (color);
	}
	t_vec3	unit_vec = normalize_vec3(ray.direction);
	t = 0.5 * (unit_vec.y + 1.0);
	color = vec3init(1.0 - 0.5 * t, 1.0 - 0.3 * t, 1.0);
	return (color);
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
	obj_cylinder.cylinder.n_vec = vec3init(0, -1, 1);
	obj_cylinder.cylinder.n_vec = normalize_vec3(obj_cylinder.cylinder.n_vec);
	obj_cylinder.cylinder.center = vec3init(3, 2, -20);
	obj_cylinder.cylinder.radius = 1.0;
	obj_cylinder.cylinder.height = 2.0;

	t_obj		obj_cone;
	obj_cone.type = CONE;
	obj_cone.cone.n_vec = vec3init(0, -1, 0);
	obj_cone.cone.n_vec = normalize_vec3(obj_cone.cone.n_vec);
	obj_cone.cone.center = vec3init(0, 0, -10);
	obj_cone.cone.radius = 2.0;
	obj_cone.cone.height = 5.0;

	t_obj	obj_sphere;
	obj_sphere.type = SPHERE;
	obj_sphere.sphere.center = vec3init(0, 0, -6);
	obj_sphere.sphere.radius = 1.0;

	t_obj	obj_plane;
	obj_plane.type = PLANE;
	obj_plane.plane.center = vec3init(0, 0, -10);
	obj_plane.plane.n_vec = normalize_vec3(vec3init(0, 1, 0));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, point_x, point_y, "test");

	t_obj	obj_cube;
	obj_cube.type = CUBE;
	obj_cube.cube.n_vec = vec3init(0, 0, 1);
	obj_cube.cube.n_vec_2 = normalize_vec3(vec3init(-1, 1, 0));
	obj_cube.cube.len = 1.0;
	obj_cube.cube.cube_c = vec3init(0, 3, -5);
	obj_cube.cube.plane[0].color = vec3init(1, 0, 0);
	obj_cube.cube.plane[1].color = vec3init(0, 0, 0);
	obj_cube.cube.plane[2].color = vec3init(0, 1, 0);
	obj_cube.cube.plane[3].color = vec3init(0, 0, 1);
	obj_cube.cube.plane[4].color = vec3init(1, 1, 0);
	obj_cube.cube.plane[5].color = vec3init(0, 1, 1);
	complete_cube(&(obj_cube.cube));

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

			t_vec3 argb = ray_color(ray, obj_cube);

			int	color = argb_(0, argb.x * 255.999, argb.y * 255.999, argb.z * 255.999);
			mlx_pixel_put(mlx.mlx, mlx.win, i, point_y - 1 - j, color);
		}
	}
	mlx_key_hook(mlx.win, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, exit_hook, 0);
	mlx_loop(mlx.mlx);
	return (0);
}
