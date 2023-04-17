/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 21:43:46 by chanson           #+#    #+#             */
/*   Updated: 2023/04/17 15:55:03 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "utils.h"

t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);
#endif