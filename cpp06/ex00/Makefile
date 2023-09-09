NAME = convert

SRCS_NAME = ./ScalarConverter ./main

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

HEADER = ./ScalarConverter.hpp

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	fclean clean all re