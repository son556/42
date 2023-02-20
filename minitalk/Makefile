SERVER_NAME = server

CLIENT_NAME = client

SERVER_SRCS = ./server.c

CLIENT_SRCS = ./client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CC = cc

FLAGS = -Wall -Wextra -Werror

LDFLAGS = -L/Users/chanson/.brew/opt/readline/lib

CPPFLAGS = -I/Users/chanson/.brew/opt/readline/include

CLIENT_FLAGS = -Wall -Wextra -Werror -lreadline

all:			ft_server ft_client

ft_server:		$(SERVER_OBJS)
				$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER_NAME)

ft_client:		$(CLIENT_OBJS)
				$(CC) $(CLIENT_FLAGS) $(LDFLAGS) $(CPPFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

clean:
				rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:			clean
				rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re:			fclean all

.PONEY:		clean all fclean re