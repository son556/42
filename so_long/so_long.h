/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 22:04:42 by chanson           #+#    #+#             */
/*   Updated: 2022/12/27 21:58:20 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "./get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_EXIT			17
# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define KEY_R						15

typedef struct s_param
{
	int		x;
	int		y;
	int		x_width;
	int		y_width;
	int		pre_x;
	int		pre_y;
	void	*mlx;
	void	*win;
}				t_param;

typedef struct s_user
{
	void	*user_e0;
	void	*user_e1;
	void	*user_e2;
	void	*user_s0;
	void	*user_s1;
	void	*user_s2;
	void	*user_w0;
	void	*user_w1;
	void	*user_w2;
	void	*user_n0;
	void	*user_n1;
	void	*user_n2;
	int		d;
	int		pre_x;
	int		pre_y;
	int		x;
	int		y;
	int		move;
	int		endian;
}				t_user;

typedef struct s_custom
{
	void	*ball;
	void	*ladder;
	void	*tile0;
	void	*tile1;
	char	*addr;
	int		cnt;
	int		x;
	int		y;
}				t_custom;

typedef struct s_map
{
	int		c;
	int		p;
	int		e;
	int		x_size;
	int		y_size;
	int		total_move;
}				t_map;

typedef struct s_node
{
	int				x;
	int				y;
	struct s_node	*next;
}				t_node;

typedef struct s_deque
{
	int		cnt;
	t_node	*front;
}				t_deque;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			**arr;
	int			**arr_2;
	int			start;
	char		*addr;
	int			key_sign;
	int			reset;
	void		*game_start;
	void		*end_img;
	void		*game_over;
	t_user		user;
	t_custom	custom;
	t_map		map;
}				t_game;

int		main_loop(t_game *g);
int		map_check(int fd, t_game *g);
void	map_size(int fd, t_game *game);
void	ft_free(int **arr, t_map *map);
void	make_map(t_game *g, int **arr, int fd);
void	make_custom(t_game *g, void *mlx);
void	make_user(t_game *g, void *mlx);
int		map_site(int **arr, t_game *g);
t_node	*new_node(int x, int y);
t_deque	*new_deque(void);
void	deque_add_back(t_deque *deque, t_node *node);
int		delete_deque(t_deque *deque);
void	delete_front_deque(t_deque *deque);
void	deque_back(t_deque *deque, int x, int y);
int		make_img(t_map *map);
int		press_key(int key_code, t_game *g);
void	put_user(t_map *m, t_user *u);
void	move_user(t_user *u);
int		draw(t_user *u);
void	draw_map(t_game *g);
void	draw_user(t_game *g);
void	dup_arr(int **arr, int **arr2, int size_x, int size_y);
void	draw_move_e(t_game *g);
void	draw_move_w(t_game *g);
void	draw_move_n(t_game *g);
void	draw_move_s(t_game *g);
void	*dir_img(t_game *g, int d);
int		close_game(t_game *game);
void	case_check(t_game *g);
void	put_image_to_window(t_game *g, int x, int y, void *image);
void	game_start(int fd, char *str, t_game *game);
int		game_restart(t_game *g);
void	find_site(int **arr, t_game *game);
#endif
