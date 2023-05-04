/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:07:40 by chanson           #+#    #+#             */
/*   Updated: 2023/05/04 19:59:38 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	complete_sphere(t_sphere *sp, t_vec3 cen, t_vec3 col, double r)
{
	sp->center = cen;
	sp->color = col;
	sp->radius = r;
}

t_vec3x3	cen_vec_col_init(t_vec3 cen, t_vec3 vec, t_color3 col)
{
	t_vec3x3	cen_vec_color;

	cen_vec_color.v_x = cen;
	cen_vec_color.v_y = normalize_vec3(vec);
	cen_vec_color.v_z = col;
	return (cen_vec_color);
}

void	complete_cyl(t_cylinder *cyl, t_vec3x3 cen_vec_col, double r, double h)
{
	cyl->center = cen_vec_col.v_x;
	cyl->n_vec = normalize_vec3(cen_vec_col.v_y);
	cyl->color = cen_vec_col.v_z;
	cyl->radius = r;
	cyl->height = h;
}

void	complete_plane(t_plane *pl, t_vec3 cen, t_vec3 vec, t_color3 col)
{
	pl->center = cen;
	pl->n_vec = vec;
	pl->color = col;
}
