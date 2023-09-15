NAME = test

SRCS_NAME = main

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

HEADER = $(addsuffix .hpp, $(SRCS_NAME))

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONEY:	all clean fclean re