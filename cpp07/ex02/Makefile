NAME = test

SRCS_NAME = main

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

HEADER = Array.hpp

TEMPLATE = Array.tpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) $(TEMPLATE)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o:	%.cpp $(HEADER) $(TEMPLATE)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all clean fclean re