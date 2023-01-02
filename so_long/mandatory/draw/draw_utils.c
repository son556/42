/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:32:46 by chanson           #+#    #+#             */
/*   Updated: 2023/01/02 16:32:47 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image_to_window(t_game *g, int x, int y, void *image)
{
	mlx_put_image_to_window(g->mlx, g->win, image, x, y);
}

void	*file_to_image(void *mlx, char *addr)
{
	int		w;
	int		h;
	void	*result;

	result = mlx_xpm_file_to_image(mlx, addr, &w, &h);
	return (result);
}
