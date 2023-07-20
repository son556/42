NAME = animal

SRCS_NAME = ./main \
			./Animal \
			./Cat \
			./Dog \
			./WrongAnimal \
			./WrongCat \

HEADER = ./Animal.hpp ./Cat.hpp ./Dog.hpp ./WrongAnimal.hpp ./WrongCat.hpp

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CXX = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

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
