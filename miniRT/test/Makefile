NAME = test

SRCS_NAME = test \
			../include/vec_utils/vec_utils \
			../include/vec_utils/vec_utils2 \
			../include/vec_utils/vec_utils3 \
			../include/vec_utils/vec_utils4 \
			../include/vec_utils/vec_utils5 \
			../include/hit/hit_cone \
			../include/hit/hit_cube \
			../include/hit/hit_cube_2 \
			../include/hit/hit_cylinder \
			../include/hit/hit \
			../include/ray

SRCS = $(addsuffix .c, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = cc

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o:	%.c
			$(CC) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			
	make fclean
	make all

.PHONEY:	clean fclean re all