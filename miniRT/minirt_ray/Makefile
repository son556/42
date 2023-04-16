NAME = minirt

SRCS_NAME = minirt \
			./include/print \
			./include/utils \
			./include/ray \
			./include/canvas \
			./include/scene \

SRCS = $(addsuffix .c, $(NAME))

OBJS = $(addsuffix .o, $(NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS):	$(SRCS)
			$(CC) $(FLAGS) $(SRCS) -c

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	clean fclean all re
