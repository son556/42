NAME = minirt

SRCS_NAME = main \
			./include/vec_utils/vec_utils \
			./include/vec_utils/vec_utils2 \
			./include/vec_utils/vec_utils3 \
			./include/vec_utils/vec_utils4 \
			./include/vec_utils/vec_utils5 \
			./include/vec_utils/vec_utils6 \
			./include/vec_utils/vec_utils7 \
			./include/ray \
			./include/mlx_functions/mlx_utils \
			./include/mlx_functions/mlx_utils2 \
			./include/hit/hit \
			./include/hit/hit_cone \
			./include/hit/hit_cone2 \
			./include/hit/hit_cylinder \
			./include/hit/hit_cylinder2 \
			./include/hit/hit_cube \
			./include/hit/hit_cube2 \
			./include/hit/hit_cube3	\
			./include/hit/hit_paraboloid \
			./include/hit/hit_paraboloid2 \
			./include/hit/hit_obj \
			./include/hit/hit_ray \
			./include/hit/hit_ray2 \
			./include/hit/hit_ray3 \
			./include/hit/hit_aabb \
			./include/hit/hit_aabb2 \
			./include/hit/hit_aabb3 \
			./include/hit/hit_noise \
			./include/hit/hit_noise2 \
			./include/hit/hit_img \
			./include/hit/hit_xyz_plane \
			./include/hit/hit_light_color \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(MLX) $(FLAGS) $(OBJS) -o $(NAME)

%.o:	%.c
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			
	make fclean
	make all

.PHONEY:	clean fclean re all