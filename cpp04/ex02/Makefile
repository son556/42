NAME = animal

SRCS_NAME = ./main \
			./Animal \
			./Cat \
			./Dog \
			./Brain \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CXX = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = ./Animal.hpp ./Cat.hpp ./Dog.hpp ./Brain.hpp

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp
		$(CXX) $(FLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:		fclean all

.PHONEY:	clean fclean re all
