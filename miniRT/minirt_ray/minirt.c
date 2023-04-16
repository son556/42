/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:24:03 by chanson           #+#    #+#             */
/*   Updated: 2023/04/16 22:17:58 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./include/structures.h"
#include <util.h>
#include "./include/print.h"
#include "./include/scene.h"
#include "./include/trace.h"

int	main(void)
{
	int			i;
	int			j;
	double		u;
	double		v;
	t_color3	pixel_color;
	t_canvas	canv;
	t_camera	cam;
	t_ray		ray;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));

	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
	// 구 만들기
}
