NAME = minirt

SRCS_NAME = main

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

CC = g++

FLAGS = -std=c++17

all:	$(NAME)

$(NAME):
			$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
			rm -rf $(NAME)

re:		clean all