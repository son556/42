NAME = miniRT

SRCS_NAME = miniRT \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

CLIB = -L./mlx -lmlx -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(CLIB) $(OBJS) -o $(NAME)

$(OBJS):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -c

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	clean fclean re all