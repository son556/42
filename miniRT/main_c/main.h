/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:45:58 by chanson           #+#    #+#             */
/*   Updated: 2023/05/31 14:47:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../include/vec3.h"
# include "../include/ray.h"
# include "../include/hit.h"
# include "../include/mlx_function.h"
# include "../include/pthread.h"
# include <stdio.h>

// main_draw
void	*draw(void *arg);
#endif