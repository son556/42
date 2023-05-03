/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:09:00 by chanson           #+#    #+#             */
/*   Updated: 2023/05/02 14:37:14 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

void	complete_cone(t_cone *con, t_vec3 cen, t_vec3 n_vec, t_vec3 rh)
{
	con->pl.n_vec = normalize_vec3(n_vec);
	con->pl.center = cen;
	con->radius = rh.x;
	con->height = rh.y;
	con->n_vec = mul_vec3(con->pl.n_vec, -1);
	con->c_h = add_vec3(con->pl.center, mul_vec3(con->pl.n_vec, con->height));
	con->c_cos = con->height / sqrt(ft_pow(con->height) + ft_pow(con->radius));
}

void	display_cone(t_cone con)
{
	display_vec3(con.pl.n_vec);
	display_vec3(con.pl.center);
	printf("r: %f h: %f\n", con.radius, con.height);
	display_vec3(con.n_vec);
	display_vec3(con.c_h);
	printf("cos: %f\n\n", con.c_cos);
}
