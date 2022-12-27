# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanson <chanson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/21 14:53:31 by chanson           #+#    #+#              #
#    Updated: 2022/12/27 11:55:19 by chanson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./so_long.c ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c ./map_check/map_check.c \
		./map_check/map_check_2.c ./make_deque/make_deque_1.c \
		./make_deque/make_deque_2.c ./view/view_map.c ./view/map_view.c \
		./view/move_user.c ./map_check/case_check.c ./utils/map_util.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC		=	gcc
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

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re