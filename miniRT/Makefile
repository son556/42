NAME = minirt

SRCS_NAME = main \
			./include/vec_utils/vec_utils \
			./include/vec_utils/vec_utils2 \
			./include/vec_utils/vec_utils3 \
			./include/vec_utils/vec_utils4 \
			./include/ray \
			./include/mlx_functions/mlx_utils \
			./include/mlx_functions/mlx_utils2 \
			./include/hit/hit \
			./include/hit/hit_cone \
			./include/hit/hit_cylinder \
			./include/hit/hit_cube \
			./include/objects \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(MLX) $(OBJS) -o $(NAME)

%.o:	%.c
			$(CC) -c $< -o $@

clean:
			@rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	clean fclean re all