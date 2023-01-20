OBJS = $(SRCS:.c=.o)

SRCS = ft_printf.c ft_printf_util.c 

NAME = libftprintf.a

LIBFT_DIR = ./libft2/

CC = cc

CFLAGS = -Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME):	$(OBJS)
			make all -C $(LIBFT_DIR)
			cp libft2/libft.a $(NAME)
			ar -rsc $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $<

clean:
			rm -f $(OBJS)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re