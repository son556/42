NAME = serialization

SRCS_NAME = Serialization \
			main \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

OBJS = $(addsuffix .o, $(SRCS_NAME))

HEADER = Serialization.hpp

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:		fclean all

.PHONEY:	all clean fclean re