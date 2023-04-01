NAME = violence

SRCS_NAME = main \
			HumanA \
			HumanB \
			Weapon \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CC = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

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