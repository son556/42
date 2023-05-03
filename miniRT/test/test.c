/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:06:26 by chanson           #+#    #+#             */
/*   Updated: 2023/05/03 14:17:15 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vec3.h"
#include "../include/hit.h"
#include <stdio.h>

int	main(void)
{
	t_rot			rot;
	t_obj			obj_cube;
	t_cube			cube;
	t_cube_plane	rot_pl;
	t_rot			rot2;

	obj_cube.type = CUBE;
	obj_cube.cube.n_vec = vec3init(0, 0, 1);
	obj_cube.cube.n_vec_2 = normalize_vec3(vec3init(1, 0, 0));
	obj_cube.cube.len = 2.0;
	obj_cube.cube.cube_c = vec3init(0, 0, 0);
	obj_cube.cube.plane[0].color = vec3init(1, 0, 0);
	obj_cube.cube.plane[1].color = vec3init(0, 0, 0);
	obj_cube.cube.plane[2].color = vec3init(0, 1, 0);
	obj_cube.cube.plane[3].color = vec3init(0, 0, 1);
	obj_cube.cube.plane[4].color = vec3init(1, 1, 0);
	obj_cube.cube.plane[5].color = vec3init(0, 1, 1);
	printf("%f\n", -0.829872 + 0.512320 - 0.220997);
	printf("%f\n", dot_vec3(vec3init(-0.829872, 0.512320, -0.220997), normalize_vec3(vec3init(1, 1, 1))));
	return (0);
}


// cc test.c ./include/vec_utils/vec_utils.c ./include/vec_utils2.c ./include/vec_utils3.c