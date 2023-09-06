NAME = test

SRCS_NAME = Bureaucrat \
			main \

SRCS = $(addsuffix .cpp, $(SRCS_NAME))

HEADER = Bureaucrat.hpp

OBJS = $(addsuffix .o, $(SRCS_NAME))

CXX = c++

CXXFLAGS = -Wall -Werror -Wall -std=c++98

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(OBJS)

re:			fclean all

.PHONEY:	all clean fclean re