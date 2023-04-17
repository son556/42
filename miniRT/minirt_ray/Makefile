NAME = minirt

SRCS_NAME = minirt \
			./include/print \
			./include/utils \
			./include/ray \
			./include/canvas \
			./include/scene \
			./include/object_create \
			./include/hit_sphere \
			./include/normal \
			./include/hit \
			./include/object_utils \
			./include/phong_lighting \

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

FLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c
			$(CC) $(FLAGS)  -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	clean fclean all re
