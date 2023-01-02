SRCS = 	./draw/draw_map.c ./draw/draw_user_move.c ./draw/draw_user.c \
		./draw/draw_utils.c ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c ./initialize/init_val.c \
		./initialize/init_img.c	./so_long.c ./make_map/read_map.c \
		./make_map/make_deque_1.c ./make_map/make_deque_2.c \
		./make_map/map_check_way.c ./make_map/map_check.c ./utils/utils.c \
		./utils/ft_itoa.c ./case_check/case_check.c ./case_check/case_check2.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC		=	gcc -g
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address
CLIB	=	-Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
			install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

%.o : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -rf $(NAME)
			rm -rf $(OBJS)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re