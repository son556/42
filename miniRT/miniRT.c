/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:39:41 by chanson           #+#    #+#             */
/*   Updated: 2023/04/11 20:33:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include <stdio.h>
#include <unistd.h>

void	write_color(double r, double g, double b)
{
	int ir = (int)min(256 * r, 255);
	int ig = (int)min(256 * g, 255);
	int ib = (int)min(256 * b, 255);
	printf("%d %d %d\n", ir, ig, ib);
}

int	main(void)
{
	double	aspect_ratio = 16.0 / 9.0;
	int		image_width = 400;
	int		image_height = (int) (image_width / aspect_ratio);

	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	t_vec3 origin = init_vec3(0, 0, 0);
	t_vec3 horizontal = init_vec3(viewport_width, 0, 0);
	t_vec3 vertical = init_vec3(0, viewport_height, 0);
	t_vec3 lower_lef_corner = init_vec3(origin.x + (- horizontal.x / 2) + (-vertical.x / 2) + (0), \
		 origin.y + (- horizontal.y / 2) + (-vertical.y / 2) + (0), \
		 origin.z + (- horizontal.z / 2) + (-vertical.z / 2) + (-focal_length));
	printf("P3\n%d %d\n255\n", image_width, image_height);
	for (int j = image_height - 1; j >= 0; j--)
	{
		for (int i = 0; i < image_width; i++)
		{
			double u = (double) i / (image_width - 1);
			double v = (double) j / (image_height - 1);
			t_vec3	temp;
			temp.x = lower_lef_corner.x + u * horizontal.x + v * vertical.x - origin.x;
			temp.y = lower_lef_corner.y + u * horizontal.y + v * vertical.y - origin.y;
			temp.z = lower_lef_corner.z + u * horizontal.z + v * vertical.z - origin.z; 
			t_ray ray = ray_init(origin, temp);
			t_color color = ray_color(ray);
			write_color(color.x, color.y, color.z);
		}
	}
}
