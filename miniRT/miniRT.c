/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:39:41 by chanson           #+#    #+#             */
/*   Updated: 2023/04/09 21:51:43 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_color(double r, double g, double b)
{
	int ir = (int)min(256 * r, 255);
	int ig = (int)min(256 * g, 255);
	int ib = (int)min(256 * b, 255);
	printf("%d %d %d\n", ir, ig, ib);
}

t_vec3	*color(t_ray *ray)
{
	t_vec3	*unit_dir;
	double	t;
	t_vec3	*cal1;
	t_vec3	*cal2;
	t_vec3	*temp;

	unit_dir = vec3_unit(&(ray->dir));
	t = 0.5 * (unit_dir->y + 1.0);
	cal1 = vec3_init(1.0, 1.0, 1.0);
	cal2 = vec3_init(0.5, 0.7, 1.0);
	temp = vec3_add(vec3_times((1.0 - t), cal1), vec3_times(t, cal2));
	return (temp);
}

int	main(void)
{
	const double	aspect_ratio = 16.0 / 9.0;
	const int		image_width = 400;
	const int		image_height = (int)(image_width / aspect_ratio);

	double	viewport_height = 2.0;
	double	viewport_width = aspect_ratio * viewport_height;
	double	focal_length = 1.0;
	t_vec3		*vec3;

	vec3 = vec3_init(0, 0, 0);
	printf("P3\n256 256\n255\n");
	for (int j = image_height - 1; j >= 0; --j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			vec3->x = (double)i / (image_width - 1);
			vec3->y = (double)j / (image_height - 1);
			vec3->z = 0.25;
			write_color(vec3->x, vec3->y, vec3->z);
		}
	}
}
