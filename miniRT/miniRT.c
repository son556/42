/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:39:41 by chanson           #+#    #+#             */
/*   Updated: 2023/04/07 22:27:36 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int		close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	mlx_destroy_image(vars->mlx, vars->win);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "Hello world!");
	mlx_hook(vars.win, 4, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
