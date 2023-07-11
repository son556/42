NAME = scavtrap

SRCS_NAME = ./main \
			./ClapTrap \
			./ScavTrap \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CXX = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o:	%.c
		$(CXX) $(FLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all

.PHONEY:	all re fclean clean