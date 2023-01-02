SRCS = 	./draw/draw_map_bonus.c ./draw/draw_user_move_bonus.c ./draw/draw_user_bonus.c \
		./draw/draw_utils_bonus.c ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c ./initialize/init_val_bonus.c \
		./initialize/init_img_bonus.c	./so_long_bonus.c ./make_map/read_map_bonus.c \
		./make_map/make_deque_1_bonus.c ./make_map/make_deque_2_bonus.c \
		./make_map/map_check_way_bonus.c ./make_map/map_check_bonus.c ./utils/utils_bonus.c \
		./utils/ft_itoa_bonus.c ./case_check/case_check_bonus.c ./case_check/case_check2_bonus.c \
		./draw/draw_enemy_bonus.c ./initialize/init_enemy_bonus.c ./draw/draw_enemy2_bonus.c

OBJS = $(SRCS:.c=.o)

NAME = so_long_bonus

CC		=	gcc -g
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

bonus:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
			install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(NAME)
			rm -rf $(OBJS)

fclean:		clean

re:			fclean bonus

.PHONY:		all clean fclean re