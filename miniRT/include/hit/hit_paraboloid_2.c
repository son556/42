/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_paraboloid_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 21:31:35 by chanson           #+#    #+#             */
/*   Updated: 2023/05/04 21:45:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

double	paraboloid_r(t_para	para)
{
	double	r;

	r = sqrt(2 * para.len * para.len_cc);
	return (r);
}

void	complete_para(t_para *para, t_vec3 center, t_vec3 move, double len)
{
	para->cen = center;
	para->pl.center = sub_vec3(para->cen, move);
	para->pl.n_vec = normalize_vec3(sub_vec3(para->cen, para->pl.center));
	para->len = len;
	para->len_cc = len_vec3(sub_vec3(para->cen, para->pl.center));
	para->r = paraboloid_r(*para);
}
