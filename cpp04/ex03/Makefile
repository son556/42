NAME = test

SRCS_NAME = ./AMateria \
			./Character \
			./Cure \
			./Ice \
			./main \
			./MateriaSource \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

CXX = clang++

FLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = AMateria.hpp Character.hpp Cure.hpp Ice.hpp MateriaSource.hpp

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
